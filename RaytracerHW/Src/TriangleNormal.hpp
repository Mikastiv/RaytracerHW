#pragma once

#include "Triangle.hpp"

class TriangleNormal : public Triangle
{
public:
    TriangleNormal(
        Material material, std::pair<Vec3f, Vec3f> v0, std::pair<Vec3f, Vec3f> v1, std::pair<Vec3f, Vec3f> v2);

    auto Shade(const Vec3f& lightDir, Vec3f lightColor, const LocalGeo& localGeo, const Vec3f& halfVec) const
        -> Vec3f override;

private:
    Vec3f mV0n;
    Vec3f mV1n;
    Vec3f mV2n;
};