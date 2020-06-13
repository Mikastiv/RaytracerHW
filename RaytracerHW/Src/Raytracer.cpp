#include "Raytracer.hpp"

#include "PointLight.hpp"
#include "Color.hpp"

#include <algorithm>

Raytracer::Raytracer(std::vector<std::shared_ptr<Shape>>&& shapes, std::vector<std::shared_ptr<Light>>&& lights)
    : mShapes(shapes)
    , mLights(lights)
{
}

auto Raytracer::Trace(const Ray& ray, const glm::vec3& eyePos) const -> Color
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
        glm::vec3 c{};
        for (const auto& l : mLights)
        {
            const auto lightRay = l->GenerateLightRay(closestIntersection->mLocalGeo.mPos);
            if (std::any_of(
                    mShapes.cbegin(), mShapes.cend(), [&lightRay](const auto& s) { return s->Intersect(lightRay); }))
                break;

            const auto lightDir = l->GetLightDirection(closestIntersection->mLocalGeo.mPos);
            const auto eyeDir = glm::normalize(eyePos - closestIntersection->mLocalGeo.mPos);
            const auto halfVec = glm::normalize(lightDir + eyeDir);

            float attenuation = 1.0f;
            if (const auto pLight = dynamic_cast<PointLight*>(l.get()))
            {
                const auto att = pLight->GetAttenuation();
                const auto d = glm::length(pLight->GetPos() - closestIntersection->mLocalGeo.mPos);
                attenuation = 1.0f / att.mKc + att.mKl * d + att.mKq * d * d;
            }

            c += attenuation *
                 closestIntersection->mShape.Shade(lightDir, l->GetColor(), closestIntersection->mLocalGeo, halfVec);
        }

        glm::vec3 retVal =
            c + closestIntersection->mShape.GetMaterial().mKa + closestIntersection->mShape.GetMaterial().mKe;

        retVal.x = glm::clamp(retVal.x, 0.0f, 1.0f);
        retVal.y = glm::clamp(retVal.y, 0.0f, 1.0f);
        retVal.z = glm::clamp(retVal.z, 0.0f, 1.0f);

        return Color{ retVal };
    }

    return Color{};
}
