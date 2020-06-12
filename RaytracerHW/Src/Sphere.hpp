#pragma once

#include "Shape.hpp"

class Sphere : public Shape
{
public:
    Sphere(Material material, Vec3f center, float radius);

    auto Intersect(const Ray<float>& ray) const -> std::optional<Intersection> override;

private:
    auto GetABCDiscriminant(const Ray<float>& ray) const -> std::tuple<float, float, float, float>;

private:
    Vec3f mCenter;
    float mRadius;
};