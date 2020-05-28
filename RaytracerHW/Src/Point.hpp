#pragma once

#include "Vec3.hpp"

template <typename T>
struct Point
{
public:
    constexpr Point() = default;
    constexpr Point(T x, T y, T z)
        : x(x)
        , y(y)
        , z(z)
    {
    }
    constexpr auto operator+=(const Vec3<T>& rhs) -> Point&
    {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }
    constexpr auto operator+(const Vec3<T>& rhs) const->Point
    {
        return Point{ *this } += rhs;
    }
    constexpr auto operator-=(const Vec3<T>& rhs)->Point&
    {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        return *this;
    }
    constexpr auto operator-(const Vec3<T>& rhs) const->Point
    {
        return Point{ *this } -= rhs;
    }
    constexpr auto operator+(const Point& rhs) const->Vec3<T>
    {
        return { x + rhs.x, y + rhs.y, z + rhs.z };
    }
    constexpr auto operator-(const Point& rhs) const->Vec3<T>
    {
        return { x - rhs.x, y - rhs.y, z - rhs.z };
    }

public:
    T x = static_cast<T>(0);
    T y = static_cast<T>(0);
    T z = static_cast<T>(0);
};