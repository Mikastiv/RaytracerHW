#pragma once

#include "Point.hpp"

template <typename T>
class Ray
{
public:
    Point<T> mPos{};
    Vec3<T> mDir{};
    T mMin = static_cast<T>(0);
    T mMax = static_cast<T>(0);
};