#include "PointLight.hpp"

PointLight::PointLight(Color color, Vec3f pos)
    : Light(std::move(color))
    , mPos(std::move(pos))
{
}

auto PointLight::GenerateLightRay(const Vec3f& srcPos) const -> Ray<float>
{
    return {mPos, Normalize(mPos - srcPos)};
}
