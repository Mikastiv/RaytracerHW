#pragma once

#include "Point.hpp"

template <typename T>
class Ray
{
public:
    Ray(Point<T> pos, Vec3<T> dir)
        : mPos(pos)
        , mDir(dir)
    {
    }

public:
    Point<T> mPos{};
    Vec3<T> mDir{};
};
