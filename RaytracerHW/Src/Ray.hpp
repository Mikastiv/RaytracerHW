#pragma once

#include "Vec3.hpp"
#include "Config.hpp"

#include <utility>

template <typename T>
struct Ray
{
public:
    constexpr Ray(Vec3<T> pos, Vec3<T> dir, float tMin = Config::TMin, float tMax = Config::TMax)
        : mOrigin(std::move(pos))
        , mDir(std::move(dir))
        , mTMin(tMin)
        , mTMax(tMax)
    {
    }

public:
    Vec3<T> mOrigin;
    Vec3<T> mDir;
    float mTMin;
    float mTMax;
};
