#pragma once

#include "Point.hpp"

#include <utility>

template <typename T>
struct Ray
{
public:
    constexpr Ray(Point<T> pos, Vec3<T> dir)
        : mOrigin(std::move(pos))
        , mDir(std::move(dir))
    {
    }

public:
    Point<T> mOrigin{};
    Vec3<T> mDir{};
};
