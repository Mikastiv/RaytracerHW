#include "Shape.hpp"

#include <algorithm>
#include <cmath>

auto Shape::Shade(const Vec3f& lightDir, Vec3f lightColor, const LocalGeo& localGeo, const Vec3f& halfVec) const
    -> Vec3f
{
    const float nDotL = Dot(localGeo.mNormal, lightDir);
    const Vec3f lambert = mMaterial.mKd * lightColor * std::max(nDotL, 0.0f);

    const float nDotH = Dot(localGeo.mNormal, halfVec);
    const Vec3f phong = mMaterial.mKs * lightColor * std::pow(std::max(nDotH, 0.0f), mMaterial.mShininess);

    return lambert + phong;
}
