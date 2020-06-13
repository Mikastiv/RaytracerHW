#pragma once

#include <cmath>
#include <cassert>
#include <algorithm>

template <typename T>
struct Vec3
{
public:
    constexpr Vec3() = default;
    constexpr Vec3(T x, T y, T z)
        : x(x)
        , y(y)
        , z(z)
    {
    }
    constexpr auto operator+=(const Vec3& rhs) -> Vec3&
    {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }
    constexpr auto operator+(const Vec3& rhs) const -> Vec3
    {
        return Vec3{ *this } += rhs;
    }
    constexpr auto operator-=(const Vec3& rhs) -> Vec3&
    {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        return *this;
    }
    constexpr auto operator-(const Vec3& rhs) const -> Vec3
    {
        return Vec3{ *this } -= rhs;
    }
    constexpr auto operator-() const -> Vec3
    {
        return { -x, -y, -z };
    }
    constexpr auto operator*=(const Vec3& rhs) -> Vec3&
    {
        x *= rhs.x;
        y *= rhs.y;
        z *= rhs.z;
        return *this;
    }
    constexpr auto operator*(const Vec3& rhs) const -> Vec3
    {
        return Vec3{ *this } *= rhs;
    }
    constexpr auto operator*=(const T& rhs) -> Vec3&
    {
        x *= rhs;
        y *= rhs;
        z *= rhs;
        return *this;
    }
    constexpr auto operator*(const T& rhs) const -> Vec3
    {
        return Vec3{ *this } *= rhs;
    }
    constexpr auto operator/=(const T& rhs) -> Vec3&
    {
        assert(rhs != static_cast<T>(0));

        x /= rhs;
        y /= rhs;
        z /= rhs;
        return *this;
    }
    constexpr auto operator/(const T& rhs) const -> Vec3
    {
        return Vec3{ *this } /= rhs;
    }
    auto Length() const -> T
    {
        return std::sqrt(x * x + y * y + z * z);
    }
    auto Normalize() -> Vec3&
    {
        const auto len = Length();
        *this /= len;
        return *this;
    }
    constexpr auto Cross(const Vec3& other) const -> Vec3
    {
        return { y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x };
    }
    constexpr auto Dot(const Vec3& other) const -> T
    {
        return static_cast<T>(x * other.x + y * other.y + z * other.z);
    }
    constexpr auto Saturate() -> Vec3&
    {
        x = std::min(std::max(static_cast<T>(0), x), static_cast<T>(1));
        y = std::min(std::max(static_cast<T>(0), y), static_cast<T>(1));
        z = std::min(std::max(static_cast<T>(0), z), static_cast<T>(1));
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
    auto newVec = Vec3<T>{ vec };
    newVec.Normalize();
    return newVec;
}

template <typename T>
inline auto Cross(const Vec3<T>& v1, const Vec3<T>& v2) -> Vec3<T>
{
    return v1.Cross(v2);
}

template <typename T>
inline auto Dot(const Vec3<T>& v1, const Vec3<T>& v2) -> T
{
    return v1.Dot(v2);
}

template <typename T>
inline auto operator*(const T& lhs, const Vec3<T>& rhs) -> Vec3<T>
{
    return rhs * lhs;
}