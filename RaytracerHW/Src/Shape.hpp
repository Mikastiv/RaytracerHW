#pragma once

#include "Intersection.hpp"
#include "Ray.hpp"
#include "Material.hpp"

#include <optional>

class Shape
{
public:
    Shape(Material material)
        : mMaterial(material)
    {
    }

    virtual auto Intersect(const Ray<float>& ray) const -> std::optional<Intersection> = 0;
    auto GetMaterial() const -> const Material&
    {
        return mMaterial;
    }

private:
    Material mMaterial;
};
