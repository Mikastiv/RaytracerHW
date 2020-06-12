#include "PointLight.hpp"

PointLight::PointLight(Color color, Vec3f pos)
    : Light(std::move(color))
    , mPos(std::move(pos))
{
}

auto PointLight::GenerateLightRay(const Vec3f& srcPos) const -> Ray<float>
{
    return {srcPos, Normalize(mPos - srcPos)};
}

auto PointLight::GetLightDirection(const Vec3f& srcPos) const -> Vec3f
{
    return Normalize(mPos - srcPos);
}
