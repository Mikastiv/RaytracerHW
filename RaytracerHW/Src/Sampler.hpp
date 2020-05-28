#pragma once

#include "Config.hpp"

#include <cstdint>
#include <optional>

class Sampler
{
public:
    Sampler(uint32_t screenWidth, uint32_t screenHeight);

    auto Sample() -> std::optional<std::pair<uint32_t, uint32_t>>;

private:
    uint32_t mScreenWidth{ Config::DefaultWidth };
    uint32_t mScreenHeight{ Config::DefaultHeight };
    uint32_t mCurrentX = 0;
    uint32_t mCurrentY = 0;
};