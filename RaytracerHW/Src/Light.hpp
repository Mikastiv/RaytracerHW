#pragma once

#include "Ray.hpp"

class Light
{
public:
    Light(Vec3f color);

    virtual auto GenerateLightRay(const Vec3f& srcPos) const -> Ray<float> = 0;
    virtual auto GetLightDirection(const Vec3f& srcPos) const -> Vec3f = 0;

    auto GetColor() const -> Vec3f
    {
        return mColor;
    }

private:
    Vec3f mColor;
};