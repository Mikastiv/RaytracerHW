#pragma once

#include "Ray.hpp"

#include <utility>
#include <cstdint>

class Camera
{
public:
    Camera() = default;
    Camera(uint32_t width, uint32_t height, float fovy, Point<float> eye);
    
    auto GenerateRay(std::pair<uint32_t, uint32_t> screenPixel) -> Ray<float>;
    auto Width() const -> uint32_t;
    auto Height() const -> uint32_t;

private:
    uint32_t mWidth = 640;
    uint32_t mHeight = 480;
    float mFovy = 60.0f;
    float mAspect = (float)mWidth / (float)mHeight;
    Point<float> mEyePos{};
};