#pragma once

#include "Shape.hpp"

class Sphere : public Shape
{
public:
    Sphere(Material material, Point<float> center, float radius);

    auto Intersect(const Ray<float>& ray) const -> std::optional<Intersection> override;

private:
    auto GetABCDiscriminant(const Ray<float>& ray) const -> std::tuple<float, float, float, float>;

private:
    Point<float> mCenter;
    float mRadius;
};