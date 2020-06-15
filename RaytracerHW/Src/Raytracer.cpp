#include "Raytracer.hpp"

#include "PointLight.hpp"
#include "Color.hpp"

#include <algorithm>

Raytracer::Raytracer(std::vector<std::shared_ptr<Shape>>&& shapes, std::vector<std::shared_ptr<Light>>&& lights)
    : mShapes(shapes)
    , mLights(lights)
{
}

auto Raytracer::Trace(const Ray& ray, const glm::vec3& eyePos, uint32_t depth) const -> glm::vec3
{
    if (depth > Config::MaxDepth)
        return {};

    std::optional<Intersection> closestIntersection{};
    for (const auto& s : mShapes)
    {
        const Ray tempRay = glm::inverse(s->GetTransform()) * ray;
        if (const auto intersection = s->Intersect(tempRay))
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

    if (!closestIntersection)
        return {};

    closestIntersection->mLocalGeo = closestIntersection->mShape.GetTransform() * closestIntersection->mLocalGeo;

    glm::vec3 color{};
    for (const auto& l : mLights)
    {
        const auto lightRay = glm::inverse(closestIntersection->mShape.GetTransform()) *
                              l->GenerateLightRay(closestIntersection->mLocalGeo.mPos);

        if (std::any_of(mShapes.cbegin(), mShapes.cend(), [&](const auto& s) { return s->Intersect(lightRay); }))
            continue;

        const auto lightDir = l->GetLightDirection(closestIntersection->mLocalGeo.mPos);
        const auto eyeDir = glm::normalize(eyePos - closestIntersection->mLocalGeo.mPos);
        const auto halfVec = glm::normalize(lightDir + eyeDir);

        float attenuation = 1.0f;
        if (const auto pLight = dynamic_cast<PointLight*>(l.get()))
        {
            const auto att = pLight->GetAttenuation();
            const auto d = glm::length(pLight->GetPos() - closestIntersection->mLocalGeo.mPos);
            attenuation = 1.0f / (att.mKc + (att.mKl * d) + (att.mKq * d * d));
        }

        color += attenuation *
                 closestIntersection->mShape.Shade(lightDir, l->GetColor(), closestIntersection->mLocalGeo, halfVec);
    }

    const float kr = closestIntersection->mShape.GetMaterial().mKr;
    if (kr > 0.0f)
    {
        const Ray tempRay = glm::inverse(closestIntersection->mShape.GetTransform()) * ray;
        const auto reflectedVec = glm::reflect(tempRay.mDir, closestIntersection->mLocalGeo.mNormal);
        const Ray reflectedRay{ closestIntersection->mLocalGeo.mPos, glm::normalize(reflectedVec) };

        const auto tempColor = Trace(reflectedRay, eyePos, ++depth);

        color += tempColor * kr;
    }

    glm::vec3 retVal =
        color + closestIntersection->mShape.GetMaterial().mKa + closestIntersection->mShape.GetMaterial().mKe;

    retVal.x = glm::clamp(retVal.x, 0.0f, 1.0f);
    retVal.y = glm::clamp(retVal.y, 0.0f, 1.0f);
    retVal.z = glm::clamp(retVal.z, 0.0f, 1.0f);

    return retVal;
}
