#pragma once

#include "Intersection.hpp"
#include "Ray.hpp"
#include "Material.hpp"

#include <optional>

class Shape
{
public:
    Shape(Material material, glm::mat4 transform)
        : mMaterial(material)
        , mTransformation(transform)
    {
    }
    virtual ~Shape() = default;

    virtual auto Intersect(const Ray& ray) const -> std::optional<Intersection> = 0;
    virtual auto
    Shade(const glm::vec3& lightDir, glm::vec3 lightColor, const LocalGeo& localGeo, const glm::vec3& halfVec) const
        -> glm::vec3;

    auto GetTransform() const -> const glm::mat4&
    {
        return mTransformation;
    }
    auto GetMaterial() const -> const Material&
    {
        return mMaterial;
    }

protected:
    glm::mat4 mTransformation{ 1.0f };

private:
    Material mMaterial;
};
