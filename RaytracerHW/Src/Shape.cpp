#include "Shape.hpp"

#include <algorithm>

auto Shape::Shade(
    const Vec3f& lightDir, Color lightColor, const LocalGeo& localGeo, const Vec3f& halfVec,
    const Material& material) const -> Color
{
    const float nDotL = Dot(localGeo.mNormal, lightDir);
    const Vec3f lambert = material.mKd.GetVec3f() * lightColor.GetVec3f() * std::max(nDotL, 0.0f);

    const float nDotH = Dot(localGeo.mNormal, halfVec);
    const Vec3f phong = material.mKs.GetVec3f() * lightColor.GetVec3f() * std::max(nDotH, 0.0f);

    return Color{ lambert + phong };
}
