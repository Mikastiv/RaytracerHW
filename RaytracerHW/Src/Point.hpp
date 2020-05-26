#pragma once

#include "Vec3.hpp"

template <typename T>
class Point
{
public:
    Point() = default;
    Point(T x, T y, T z)
        : x(x)
        , y(y)
        , z(z)
    {
    }
    auto operator+=(const Vec3<T>& rhs) -> Point&
    {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }
    auto operator+(const Vec3<T>& rhs) const -> Point
    {
        return Point{ *this } += rhs;
    }
    auto operator-=(const Vec3<T>& rhs) -> Point&
    {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        return *this;
    }
    auto operator-(const Vec3<T>& rhs) const -> Point
    {
        return Point{ *this } -= rhs;
    }
    auto operator+(const Point& rhs) const -> Vec3<T>
    {
        return { x + rhs.x, y + rhs.y, z + rhs.z };
    }
    auto operator-(const Point& rhs) const -> Vec3<T>
    {
        return { x - rhs.x, y - rhs.y, z - rhs.z };
    }

public:
    T x;
    T y;
    T z;
};