#pragma once

#include "Vec3.hpp"
#include "Config.hpp"

#include <utility>

template <typename T>
struct Ray
{
public:
    constexpr Ray(Vec3<T> pos, Vec3<T> dir,  float tMax = Config::TMax, float tMin = Config::TMin)
        : mOrigin(std::move(pos))
        , mDir(std::move(dir))
        , mTMax(tMax)
        , mTMin(tMin)
    {
    }

public:
    Vec3<T> mOrigin;
    Vec3<T> mDir;
    float mTMax;
    float mTMin;
};
