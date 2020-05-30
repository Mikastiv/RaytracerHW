#pragma once

#include "Config.hpp"
#include "Ray.hpp"

#include <utility>
#include <cstdint>

class Camera
{
public:
    Camera(uint32_t width, uint32_t height, float fovy, Point<float> eye, Point<float> lookAt, Vec3f up);

    auto GenerateRay(std::pair<uint32_t, uint32_t> screenPixel) -> Ray<float>;
    auto Width() const -> uint32_t;
    auto Height() const -> uint32_t;

private:
    uint32_t mWidth;
    uint32_t mHeight;
    float mFovy;
    float mAspect;
    Point<float> mEyePos;
    Point<float> mLookAt;
    Vec3f mUp;
    // Order is important here
    Vec3f mW;
    Vec3f mU;
    Vec3f mV;
};