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
    virtual auto Shade(const Vec3f& lightDir, Vec3f lightColor, const LocalGeo& localGeo, const Vec3f& halfVec) const
        -> Vec3f;

    auto GetMaterial() const -> const Material&
    {
        return mMaterial;
    }

private:
    Material mMaterial;
};
