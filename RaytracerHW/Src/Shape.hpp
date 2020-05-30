#pragma once

#include "LocalGeo.hpp"
#include "Ray.hpp"

#include <optional>
#include <tuple>

class Shape
{
public:
    virtual auto Intersect(const Ray<float>& ray) const -> std::optional<LocalGeo> = 0;
};
