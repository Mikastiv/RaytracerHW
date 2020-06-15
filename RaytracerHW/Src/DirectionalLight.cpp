#include "DirectionalLight.hpp"

#include <glm/glm.hpp>
#include <limits>

DirectionalLight::DirectionalLight(glm::vec3 color, glm::vec3 dir)
    : Light(std::move(color))
    , mDir(glm::normalize(dir))
{
}

auto DirectionalLight::GenerateLightRay(const glm::vec3& srcPos) const -> Ray
{
    return { srcPos, -mDir, std::numeric_limits<float>::infinity() };
}

auto DirectionalLight::GetLightDirection(const glm::vec3& srcPos) const -> glm::vec3
{
    return -mDir;
}
