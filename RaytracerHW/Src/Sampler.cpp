#include "Sampler.hpp"

Sampler::Sampler(uint32_t screenWidth, uint32_t screenHeight)
    : mScreenWidth(screenWidth)
    , mScreenHeight(screenHeight)
{
}

auto Sampler::Sample() -> std::optional<std::pair<uint32_t, uint32_t>>
{
    const auto point = std::make_pair(mCurrentX, mCurrentY);

    if (++mCurrentX >= mScreenWidth)
    {
        mCurrentX = 0;
        mCurrentY++;
    }

    if (mCurrentY >= mScreenHeight && mCurrentX > 0)
    {
        return {};
    }

    return point;
}
