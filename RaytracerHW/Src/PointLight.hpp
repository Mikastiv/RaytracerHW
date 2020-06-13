#pragma once

#include "Light.hpp"

class PointLight : public Light
{
public:
    struct Attenuation
    {
        float mKc;
        float mKl;
        float mKq;
    };

public:
    PointLight(glm::vec3 color, glm::vec3 pos, Attenuation attenuation);

    auto GenerateLightRay(const glm::vec3& srcPos) const -> Ray override;
    auto GetLightDirection(const glm::vec3& srcPos) const -> glm::vec3 override;

    auto GetAttenuation() const -> Attenuation;
    auto GetPos() const -> glm::vec3;

private:
    glm::vec3 mPos;
    Attenuation mAttenuation;
};