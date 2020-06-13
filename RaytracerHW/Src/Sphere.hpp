#pragma once

#include "Shape.hpp"

class Sphere : public Shape
{
public:
    Sphere(Material material, glm::vec3 center, float radius);

    auto Intersect(const Ray& ray) const -> std::optional<Intersection> override;

private:
    auto GetABCDiscriminant(const Ray& ray) const -> std::tuple<float, float, float, float>;

private:
    glm::vec3 mCenter;
    float mRadius;
};