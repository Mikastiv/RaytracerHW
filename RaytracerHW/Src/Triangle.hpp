#pragma once

#include "Shape.hpp"

class Triangle : public Shape
{
public:
    Triangle(Material material, glm::mat4 transform, glm::vec3 v0, glm::vec3 v1, glm::vec3 v2);

    auto Intersect(const Ray& ray) const -> std::optional<Intersection> override;

protected:
    glm::vec3 mV0;
    glm::vec3 mV1;
    glm::vec3 mV2;
};