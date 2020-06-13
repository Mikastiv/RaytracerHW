#pragma once

#include "Config.hpp"
#include "Ray.hpp"

#include <utility>
#include <cstdint>

class Camera
{
public:
    Camera(uint32_t width, uint32_t height, float fovy, glm::vec3 eye, glm::vec3 lookAt, glm::vec3 up);

    auto GenerateRay(std::pair<uint32_t, uint32_t> screenPixel) -> Ray;
    auto GetWidth() const -> uint32_t;
    auto GetHeight() const -> uint32_t;
    auto GetEyePos() const -> glm::vec3;

private:
    uint32_t mWidth;
    uint32_t mHeight;
    float mFovy;
    float mAspect;
    glm::vec3 mEyePos;
    glm::vec3 mLookAt;
    glm::vec3 mUp;
    // Order is important here
    glm::vec3 mW;
    glm::vec3 mU;
    glm::vec3 mV;
};