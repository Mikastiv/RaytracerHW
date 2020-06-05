#include "Raytracer.hpp"

Raytracer::Raytracer(std::vector<std::shared_ptr<Shape>>&& shapes)
    : mShapes(shapes)
{
}

auto Raytracer::Intersect(const Ray<float>& ray) const -> Color
{
    std::optional<Intersection> closestIntersection{};
    for (const auto& s : mShapes)
    {
        if (const auto intersection = s->Intersect(ray))
        {
            if (!closestIntersection)
            {
                closestIntersection.emplace(*intersection);
            }
            else if (closestIntersection->mLocalGeo.mHitDistance > intersection->mLocalGeo.mHitDistance)
            {
                closestIntersection.emplace(*intersection);
            }
        }
    }

    if (closestIntersection)
    {
        return Color{ 1.0f, 1.0f, 0.0f };
    }

    return Color{};
}
