#include "DirectionalLight.hpp"

#include <limits>

DirectionalLight::DirectionalLight(Color color, Vec3f dir)
    : Light(std::move(color))
    , mDir(Normalize(dir))
{
}

auto DirectionalLight::GenerateLightRay(const Vec3f& srcPos) const -> Ray<float>
{
    return { srcPos, -mDir, std::numeric_limits<float>::max() };
}
