#include "Sphere.hpp"

#include <algorithm>
#include <cmath>
#include <tuple>

Sphere::Sphere(Material material, Point<float> center, float radius)
    : Shape(material)
    , mCenter(std::move(center))
    , mRadius(radius)
{
}

auto Sphere::Intersect(const Ray<float>& ray) const -> std::optional<Intersection>
{
    const auto [a, b, c, disc] = GetABCDiscriminant(ray);

    if (disc < 0.0f)
        return {};

    const float sqDisc = sqrtf(disc);
    const float t1 = (-b + sqDisc) / (2.0f * a);
    const float t2 = (-b - sqDisc) / (2.0f * a);

    float t = 0.0f;
    if (t1 > 0.0f && t2 > 0.0f)
    {
        t = std::min(t1, t2);
    }
    else if (std::signbit(t1) != std::signbit(t2))
    {
        t = std::max(t1, t2);
    }
    else
    {
        t = t1;
    }

    const auto intersectPoint = ray.mOrigin + ray.mDir * t;
    return Intersection{ *this, { intersectPoint, intersectPoint - mCenter, t1 } };
}

auto Sphere::GetABCDiscriminant(const Ray<float>& ray) const -> std::tuple<float, float, float, float>
{
    const auto oc = ray.mOrigin - mCenter;
    const float a = Dot(ray.mDir, ray.mDir);
    const float b = 2.0f * Dot(ray.mDir, oc);
    const float c = Dot(oc, oc) - (mRadius * mRadius);

    const float discriminant = (b * b) - (4 * a * c);

    return { a, b, c, discriminant };
}
