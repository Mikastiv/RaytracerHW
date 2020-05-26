#pragma once

#include <cmath>
#include <cassert>

template <typename T>
struct Vec3
{
public:
    Vec3() = default;
    Vec3(T x, T y, T z)
        : x(x)
        , y(y)
        , z(z)
    {
    }
    auto operator+=(const Vec3& rhs) -> Vec3&
    {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }
    auto operator+(const Vec3& rhs) const -> Vec3
    {
        return Vec3{ *this } += rhs;
    }
    auto operator-=(const Vec3& rhs) -> Vec3&
    {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        return *this;
    }
    auto operator-(const Vec3& rhs) const -> Vec3
    {
        return Vec3{ *this } -= rhs;
    }
    auto operator*=(const T& rhs) -> Vec3&
    {
        x *= rhs;
        y *= rhs;
        z *= rhs;
        return *this;
    }
    auto operator*(const T& rhs) const -> Vec3
    {
        return Vec3{ *this } *= rhs;
    }
    auto operator/=(const T& rhs) -> Vec3&
    {
        assert(rhs != static_cast<T>(0));

        x /= rhs;
        y /= rhs;
        z /= rhs;
        return *this;
    }
    auto operator/(const T& rhs) const -> Vec3
    {
        return Vec3{ *this } /= rhs;
    }
    auto Length() const -> T
    {
        return sqrt(x * x + y * y + z * z);
    }
    auto Normalize() -> Vec3&
    {
        const auto len = Length();
        *this /= len;
        return *this;
    }

public:
    T x = static_cast<T>(0);
    T y = static_cast<T>(0);
    T z = static_cast<T>(0);
};

using Vec3f = Vec3<float>;

template <typename T>
inline auto Normalize(const Vec3<T>& vec) -> Vec3<T>
{
    const auto len = vec.Length();
    return { vec.x / len, vec.y / len, vec.z / len };
}

template <typename T>
inline auto operator*(const T& lhs, const Vec3<T>& rhs) -> Vec3<T>
{
    return Vec3{ rhs } * lhs;
}

template <typename T>
inline auto operator/(const T& lhs, const Vec3<T>& rhs) -> Vec3<T>
{
    return Vec3{ rhs } / lhs;
}