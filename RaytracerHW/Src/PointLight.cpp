#include "PointLight.hpp"

PointLight::PointLight(Vec3f color, Vec3f pos, Attenuation attenuation)
    : Light(std::move(color))
    , mPos(std::move(pos))
    , mAttenuation(std::move(attenuation))
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

auto PointLight::GetAttenuation() const -> Attenuation
{
    return mAttenuation;
}

auto PointLight::GetPos() const -> Vec3f
{
    return mPos;
}
