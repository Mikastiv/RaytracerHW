#include "DirectionalLight.hpp"

#include <limits>

DirectionalLight::DirectionalLight(Color color, Vec3f pos)
    : Light(std::move(color))
    , mDir(std::move(pos))
{
}

auto DirectionalLight::GenerateLightRay(const Vec3f& srcPos) const -> Ray<float>
{
    return { srcPos, mDir, std::numeric_limits<float>::max() };
}
