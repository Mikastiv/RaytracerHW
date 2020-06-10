#pragma once

#include "Triangle.hpp"

class TriangleNormal : public Triangle
{
public:
    TriangleNormal(
        Material material, std::pair<Vec3f, Vec3f> v0, std::pair<Vec3f, Vec3f> v1, std::pair<Vec3f, Vec3f> v2);

private:
    Vec3f mV0n;
    Vec3f mV1n;
    Vec3f mV2n;
};