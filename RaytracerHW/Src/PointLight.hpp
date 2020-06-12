#pragma once

#include "Light.hpp"

class PointLight : public Light
{
public:
    PointLight(Color color, Vec3f pos);

    auto GenerateLightRay(const Vec3f& srcPos) const -> Ray<float> override;
    auto GetLightDirection(const Vec3f& srcPos) const -> Vec3f override;

private:
    Vec3f mPos;
};