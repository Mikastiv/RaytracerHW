#pragma once

#include "Vec3.hpp"

#include <utility>

template <typename T>
struct Ray
{
public:
    constexpr Ray(Vec3<T> pos, Vec3<T> dir)
        : mOrigin(std::move(pos))
        , mDir(std::move(dir))
    {
    }

public:
    Vec3<T> mOrigin;
    Vec3<T> mDir;
};
