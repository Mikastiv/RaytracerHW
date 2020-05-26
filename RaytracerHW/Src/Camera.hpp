#pragma once

#include "Ray.hpp"

#include <utility>
#include <cstdint>

class Camera
{
public:
    Camera() = default;
    Camera(float fovy, float aspect);
    
    auto GenerateRay(std::pair<uint32_t, uint32_t> screenPixel) -> Ray<float>;

private:
    float mFovy = 60.0f;
    float mAspect = 4.0f / 3.0f;
};