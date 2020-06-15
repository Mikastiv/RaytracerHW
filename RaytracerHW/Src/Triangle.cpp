#include "Triangle.hpp"
#include "Config.hpp"

Triangle::Triangle(Material material, glm::vec3 v0, glm::vec3 v1, glm::vec3 v2)
    : Shape(material)
    , mV0(std::move(v0))
    , mV1(std::move(v1))
    , mV2(std::move(v2))
{
}

auto Triangle::Intersect(const Ray& ray) const -> std::optional<Intersection>
{
    const glm::vec3 edge1 = mV1 - mV0;
    const glm::vec3 edge2 = mV2 - mV0;
    const glm::vec3 h = glm::cross(ray.mDir, edge2);
    const float det = glm::dot(edge1, h);

    if (std::fabs(det) < Config::Epsilon)
        return {};

    const float invDet = 1.0f / det;
    const glm::vec3 s = ray.mOrigin - mV0;
    const float u = glm::dot(s, h) * invDet;

    if (u < 0.0f || u > 1.0f)
        return {};

    const glm::vec3 q = glm::cross(s, edge1);
    const float v = glm::dot(ray.mDir, q) * invDet;

    if (v < 0.0f || u + v > 1.0f)
        return {};

    const float t = glm::dot(edge2, q) * invDet;

    if (t < Config::Epsilon)
        return {};

    if (t < ray.mTMin || t > ray.mTMax)
        return {};

    const glm::vec3 intersectPoint = ray.mOrigin + ray.mDir * t;
    const auto normal = glm::normalize(glm::cross(mV2 - mV0, mV1 - mV0));

    return Intersection{ *this, { intersectPoint + (normal * Config::Epsilon), normal, t } };
}
