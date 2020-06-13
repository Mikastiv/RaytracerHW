#pragma once

#include "Shape.hpp"
#include "Light.hpp"
#include "Color.hpp"

#include <vector>
#include <memory>

class Raytracer
{
public:
    Raytracer(std::vector<std::shared_ptr<Shape>>&& shapes, std::vector<std::shared_ptr<Light>>&& lights);

    auto Trace(const Ray& ray, const glm::vec3& eyePos) const -> Color;

private:
    std::vector<std::shared_ptr<Shape>> mShapes;
    std::vector<std::shared_ptr<Light>> mLights;
};