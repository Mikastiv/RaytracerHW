#pragma once

#include "Ray.hpp"

class Light
{
public:
    Light(Color color);

    virtual auto GenerateLightRay(const Vec3f& srcPos) const -> Ray<float> = 0;

private:
    Color mColor;
};