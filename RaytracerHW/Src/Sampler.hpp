#pragma once

#include <cstdint>
#include <optional>

class Sampler
{
public:
    Sampler() = default;
    Sampler(uint32_t screenWidth, uint32_t screenHeight);

    auto Sample() -> std::optional<std::pair<uint32_t, uint32_t>>;

private:
    uint32_t mScreenWidth = 0;
    uint32_t mScreenHeight = 0;
    uint32_t mCurrentX = 0;
    uint32_t mCurrentY = 0;
};