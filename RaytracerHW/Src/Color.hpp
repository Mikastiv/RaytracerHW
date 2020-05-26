#pragma once

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
    constexpr auto GetR() const noexcept -> uint8_t
    {
        return mR;
    }
    constexpr auto GetRNorm() const noexcept -> float
    {
        return (float)mR / 255.0f;
    }
    constexpr auto GetG() const noexcept -> uint8_t
    {
        return mG;
    }
    constexpr auto GetGNorm() const noexcept -> float
    {
        return (float)mG / 255.0f;
    }
    constexpr auto GetB() const noexcept -> uint8_t
    {
        return mB;
    }
    constexpr auto GetBNorm() const noexcept -> float
    {
        return (float)mB / 255.0f;
    }
    constexpr auto GetRGBNorm() const noexcept -> std::tuple<float, float, float>
    {
        return { GetRNorm(), GetGNorm(), GetBNorm() };
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