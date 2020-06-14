#include "PointLight.hpp"

#include <glm/glm.hpp>

PointLight::PointLight(glm::vec3 color, glm::vec3 pos, Attenuation attenuation)
    : Light(std::move(color))
    , mPos(std::move(pos))
    , mAttenuation(std::move(attenuation))
{
}

auto PointLight::GenerateLightRay(const glm::vec3& srcPos) const -> Ray
{
    return { srcPos, GetLightDirection(srcPos) };
}

auto PointLight::GetLightDirection(const glm::vec3& srcPos) const -> glm::vec3
{
    return glm::normalize(mPos - srcPos);
}

auto PointLight::GetAttenuation() const -> Attenuation
{
    return mAttenuation;
}

auto PointLight::GetPos() const -> glm::vec3
{
    return mPos;
}
