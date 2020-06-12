#pragma once

#include "Vec3.hpp"

#include <cstdint>
#include <tuple>
#include <limits>
#include <algorithm>

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
        : mR((uint8_t)std::min(
              uint32_t(r * std::numeric_limits<uint8_t>::max()), (uint32_t)std::numeric_limits<uint8_t>::max()))
        , mG((uint8_t)std::min(
              uint32_t(g * std::numeric_limits<uint8_t>::max()), (uint32_t)std::numeric_limits<uint8_t>::max()))
        , mB((uint8_t)std::min(
              uint32_t(b * std::numeric_limits<uint8_t>::max()), (uint32_t)std::numeric_limits<uint8_t>::max()))
    {
    }
    constexpr Color(Vec3f rgb) noexcept
        : mR((uint8_t)std::min(
              uint32_t(rgb.x * std::numeric_limits<uint8_t>::max()), (uint32_t)std::numeric_limits<uint8_t>::max()))
        , mG((uint8_t)std::min(
              uint32_t(rgb.y * std::numeric_limits<uint8_t>::max()), (uint32_t)std::numeric_limits<uint8_t>::max()))
        , mB((uint8_t)std::min(
              uint32_t(rgb.z * std::numeric_limits<uint8_t>::max()), (uint32_t)std::numeric_limits<uint8_t>::max()))
    {
    }
    constexpr auto operator+=(const Color& rhs) -> Color&
    {
        const uint16_t r = (uint16_t)mR + rhs.mR;
        const uint16_t g = (uint16_t)mG + rhs.mG;
        const uint16_t b = (uint16_t)mB + rhs.mB;

        mR = (uint8_t)std::min(r, (uint16_t)std::numeric_limits<uint8_t>::max());
        mG = (uint8_t)std::min(g, (uint16_t)std::numeric_limits<uint8_t>::max());
        mB = (uint8_t)std::min(b, (uint16_t)std::numeric_limits<uint8_t>::max());

        return *this;
    }
    constexpr auto operator+(const Color& rhs) const -> Color
    {
        return Color{ *this } += rhs;
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