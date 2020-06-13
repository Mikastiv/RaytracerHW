#pragma once

#include "Ray.hpp"

class Light
{
public:
    Light(glm::vec3 color);

    virtual auto GenerateLightRay(const glm::vec3& srcPos) const -> Ray = 0;
    virtual auto GetLightDirection(const glm::vec3& srcPos) const -> glm::vec3 = 0;

    auto GetColor() const -> glm::vec3
    {
        return mColor;
    }

private:
    glm::vec3 mColor;
};