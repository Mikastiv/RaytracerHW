#pragma once

#include "Point.hpp"

#include <utility>

struct LocalGeo
{
public:
    constexpr LocalGeo(Point<float> pos, Vec3f normal, float hitDistance)
        : mPos(std::move(pos))
        , mNormal(std::move(normal.Normalize()))
        , mHitDistance(hitDistance)
    {
    }

public:
    Point<float> mPos;
    Vec3f mNormal;
    float mHitDistance;
};