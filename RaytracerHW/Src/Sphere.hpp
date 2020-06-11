#pragma once

#include "Shape.hpp"

class Sphere : public Shape
{
public:
    Sphere(Material material, Vec3f center, float radius);

    auto Intersect(const Ray<float>& ray) const -> std::optional<Intersection> override;
    auto Shade(
        const Vec3f& lightDir, Color lightColor, const Vec3f& normal, const Vec3f& halfVec,
        const Material& material) const -> Color override;

private:
    auto GetABCDiscriminant(const Ray<float>& ray) const -> std::tuple<float, float, float, float>;

private:
    Vec3f mCenter;
    float mRadius;
};