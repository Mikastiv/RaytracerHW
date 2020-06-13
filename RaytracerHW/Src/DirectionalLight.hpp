#pragma once

#include "Light.hpp"

class DirectionalLight : public Light
{
public:
    DirectionalLight(Vec3f color, Vec3f dir);

    auto GenerateLightRay(const Vec3f& srcPos) const -> Ray<float> override;
    auto GetLightDirection(const Vec3f& srcPos) const -> Vec3f override;

private:
    Vec3f mDir;
};