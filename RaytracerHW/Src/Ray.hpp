#pragma once

#include "Point.hpp"

template <typename T>
class Ray
{
public:
    Ray(Point<T> pos, Vec3<T> dir)
        : mOrigin(pos)
        , mDir(dir)
    {
    }

public:
    Point<T> mOrigin{};
    Vec3<T> mDir{};
};
