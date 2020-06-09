#pragma once

#include "Light.hpp"

class DirectionalLight : public Light
{
public:
    DirectionalLight(Color color, Vec3f dir);

    auto GenerateLightRay(const Vec3f& srcPos) const -> Ray<float> override;

private:
    Vec3f mDir;
};