#pragma once

#include "Light.hpp"

class DirectionalLight : public Light
{
public:
    DirectionalLight(glm::vec3 color, glm::vec3 dir);

    auto GenerateLightRay(const glm::vec3& srcPos) const -> Ray override;
    auto GetLightDirection(const glm::vec3& srcPos) const -> glm::vec3 override;

private:
    glm::vec3 mDir;
};