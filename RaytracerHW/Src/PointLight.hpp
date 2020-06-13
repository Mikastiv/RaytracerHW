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
    PointLight(Vec3f color, Vec3f pos, Attenuation attenuation);

    auto GenerateLightRay(const Vec3f& srcPos) const -> Ray<float> override;
    auto GetLightDirection(const Vec3f& srcPos) const -> Vec3f override;

    auto GetAttenuation() const -> Attenuation;
    auto GetPos() const -> Vec3f;

private:
    Vec3f mPos;
    Attenuation mAttenuation;
};