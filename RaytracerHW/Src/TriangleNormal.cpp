#include "TriangleNormal.hpp"

TriangleNormal::TriangleNormal(
    Material material, std::pair<Vec3f, Vec3f> v0, std::pair<Vec3f, Vec3f> v1, std::pair<Vec3f, Vec3f> v2)
    : Triangle(std::move(material), v0.first, v1.first, v2.first)
    , mV0n(v0.second)
    , mV1n(v1.second)
    , mV2n(v2.second)
{
}

auto TriangleNormal::Shade(
    const Vec3f& lightDir, Color lightColor, const LocalGeo& localGeo, const Vec3f& halfVec,
    const Material& material) const -> Color
{
    return Shape::Shade(lightDir, lightColor, localGeo, halfVec, material);
}
