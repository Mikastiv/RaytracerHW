#pragma once

#include "Vec3.hpp"

#include <utility>

struct LocalGeo
{
public:
    constexpr LocalGeo(Vec3f pos, Vec3f normal, float hitDistance)
        : mPos(std::move(pos))
        , mNormal(std::move(normal.Normalize()))
        , mHitDistance(hitDistance)
    {
    }

public:
    Vec3f mPos;
    Vec3f mNormal;
    float mHitDistance;
};