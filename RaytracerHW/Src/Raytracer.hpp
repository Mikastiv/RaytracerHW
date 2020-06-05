#pragma once

#include "Shape.hpp"

#include <vector>
#include <memory>

class Raytracer
{
public:
    Raytracer(std::vector<std::shared_ptr<Shape>>&& shapes);

    auto Intersect(const Ray<float>& ray) const -> Color;

private:
    std::vector<std::shared_ptr<Shape>> mShapes;
};