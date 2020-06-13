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

    virtual auto Intersect(const Ray& ray) const -> std::optional<Intersection> = 0;
    virtual auto
    Shade(const glm::vec3& lightDir, glm::vec3 lightColor, const LocalGeo& localGeo, const glm::vec3& halfVec) const
        -> glm::vec3;

    auto GetMaterial() const -> const Material&
    {
        return mMaterial;
    }

private:
    Material mMaterial;
};
