#pragma once

#include "Config.hpp"
#include "Ray.hpp"

#include <utility>
#include <cstdint>

class Camera
{
public:
    Camera(uint32_t width, uint32_t height, float fovy, Vec3f eye, Vec3f lookAt, Vec3f up);

    auto GenerateRay(std::pair<uint32_t, uint32_t> screenPixel) -> Ray<float>;
    auto GetWidth() const -> uint32_t;
    auto GetHeight() const -> uint32_t;
    auto GetEyePos() const -> Vec3f;

private:
    uint32_t mWidth;
    uint32_t mHeight;
    float mFovy;
    float mAspect;
    Vec3f mEyePos;
    Vec3f mLookAt;
    Vec3f mUp;
    // Order is important here
    Vec3f mW;
    Vec3f mU;
    Vec3f mV;
};