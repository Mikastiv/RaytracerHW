#include "Raytracer.hpp"

#include <algorithm>

Raytracer::Raytracer(std::vector<std::shared_ptr<Shape>>&& shapes, std::vector<std::shared_ptr<Light>>&& lights)
    : mShapes(shapes)
    , mLights(lights)
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
        Color c{};
        for (const auto& l : mLights)
        {
            const auto lightRay = l->GenerateLightRay(closestIntersection->mLocalGeo.mPos);
            if (std::any_of(
                    mShapes.cbegin(), mShapes.cend(), [&lightRay](const auto& s) { return s->Intersect(lightRay); }))
                break;

            // shading
        }
        return c;
    }

    return Color{};
}
