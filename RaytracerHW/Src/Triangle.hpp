#pragma once

#include "Shape.hpp"

class Triangle : public Shape
{
public:
    Triangle(Material material, Vec3f v0, Vec3f v1, Vec3f v2);

    auto Intersect(const Ray<float>& ray) const -> std::optional<Intersection> override;

protected:
    Vec3f mV0;
    Vec3f mV1;
    Vec3f mV2;
};