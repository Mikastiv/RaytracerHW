#pragma once

#include "Shape.hpp"
#include "Light.hpp"

#include <vector>
#include <memory>

class Raytracer
{
public:
    Raytracer(std::vector<std::shared_ptr<Shape>>&& shapes, std::vector<std::shared_ptr<Light>>&& lights);

    [[nodiscard]] auto Trace(const Ray& ray, const glm::vec3& eyePos, uint32_t depth = 0) const -> glm::vec3;

private:
    std::vector<std::shared_ptr<Shape>> mShapes;
    std::vector<std::shared_ptr<Light>> mLights;
};