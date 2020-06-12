#pragma once

#include "Vec3.hpp"

#include <cstdint>
#include <tuple>

// RGB
class Color
{
public:
    static constexpr int ChannelCount = 3;

public:
    constexpr Color() noexcept = default;
    constexpr Color(uint8_t r, uint8_t g, uint8_t b) noexcept
        : mR(r)
        , mG(g)
        , mB(b)
    {
    }
    constexpr Color(float r, float g, float b) noexcept
        : mR(uint8_t(r * 255.0f))
        , mG(uint8_t(g * 255.0f))
        , mB(uint8_t(b * 255.0f))
    {
    }
    constexpr Color(Vec3f rgb) noexcept
        : mR(uint8_t(rgb.x * 255.0f))
        , mG(uint8_t(rgb.y * 255.0f))
        , mB(uint8_t(rgb.z * 255.0f))
    {
    }
    constexpr auto operator+=(const Color& rhs) -> Color&
    {
        mR += rhs.mR;
        mG += rhs.mG;
        mB += rhs.mB;
        return *this;
    }
    constexpr auto GetR() const noexcept -> uint8_t
    {
        return mR;
    }
    constexpr auto GetG() const noexcept -> uint8_t
    {
        return mG;
    }
    constexpr auto GetB() const noexcept -> uint8_t
    {
        return mB;
    }
    constexpr auto GetRGB() const noexcept -> std::tuple<uint8_t, uint8_t, uint8_t>
    {
        return { GetR(), GetG(), GetB() };
    }
    constexpr auto GetVec3f() const noexcept -> Vec3f
    {
        return { float(mR) / 255.0f, float(mG) / 255.0f, float(mB) / 255.0f };
    }
    auto SetR(uint8_t r) noexcept -> void
    {
        mR = r;
    }
    auto SetG(uint8_t g) noexcept -> void
    {
        mG = g;
    }
    auto SetB(uint8_t b) noexcept -> void
    {
        mB = b;
    }

private:
    uint8_t mR = 0;
    uint8_t mG = 0;
    uint8_t mB = 0;
};