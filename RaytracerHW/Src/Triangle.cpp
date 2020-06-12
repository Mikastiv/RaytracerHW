#include "Triangle.hpp"
#include "Config.hpp"

Triangle::Triangle(Material material, Vec3f v0, Vec3f v1, Vec3f v2)
    : Shape(material)
    , mV0(std::move(v0))
    , mV1(std::move(v1))
    , mV2(std::move(v2))
{
}

auto Triangle::Intersect(const Ray<float>& ray) const -> std::optional<Intersection>
{
    const Vec3f edge1 = mV1 - mV0;
    const Vec3f edge2 = mV2 - mV0;
    const Vec3f h = Cross(ray.mDir, edge2);
    const float det = Dot(edge1, h);

    if (std::fabs(det) < Config::Epsilon)
        return {};

    const float invDet = 1.0f / det;
    const Vec3f s = ray.mOrigin - mV0;
    const float u = Dot(s, h) * invDet;

    if (u < 0.0f || u > 1.0f)
        return {};

    const Vec3f q = Cross(s, edge1);
    const float v = Dot(ray.mDir, q) * invDet;

    if (v < 0.0f || u + v > 1.0f)
        return {};

    const float t = Dot(edge2, q) * invDet;

    if (t < Config::Epsilon)
        return {};

    if (t < ray.mTMin || t > ray.mTMax)
        return {};

    const Vec3f intersectPoint = ray.mOrigin + ray.mDir * t;
    const auto normal = Cross((mV2 - mV0), (mV1 - mV0)).Normalize();

    return Intersection{ *this, { intersectPoint + (Config::Epsilon * normal), normal, t } };
}
