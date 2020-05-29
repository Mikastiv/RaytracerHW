#pragma once

#include "Point.hpp"

#include <utility>

struct LocalGeo
{
public:
    constexpr LocalGeo(Point<float> pos, Vec3f normal)
        : mPos(std::move(pos))
        , mNormal(std::move(normal.Normalize()))
    {
    }

public:
    Point<float> mPos{};
    Vec3f mNormal{};
};