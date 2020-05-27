#include "Camera.hpp"

Camera::Camera(uint32_t width, uint32_t height, float fovy, Point<float> eye)
    : mWidth(width)
    , mHeight(height)
    , mFovy(fovy)
    , mAspect((float)width / (float)height)
    , mEyePos(std::move(eye))
{
}

auto Camera::Width() const -> uint32_t
{
    return mWidth;
}

auto Camera::Height() const -> uint32_t
{
    return mHeight;
}
