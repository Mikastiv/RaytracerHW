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
    uint32_t mWidth{ Config::DefaultWidth };
    uint32_t mHeight{ Config::DefaultHeight };
    float mFovy{ Config::DefaultFovy };
    float mAspect = (float)mWidth / (float)mHeight;
    Point<float> mEyePos{ Config::DefaultEyePos };
    Point<float> mLookAt{ Config::DefaultLookAt };
    Vec3f mUp{ Config::DefaultUp };
    Vec3f mW{};
    Vec3f mU{};
    Vec3f mV{};
};