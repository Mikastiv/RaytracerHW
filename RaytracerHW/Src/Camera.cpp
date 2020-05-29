#include "Camera.hpp"

#include "Utils.hpp"

Camera::Camera(uint32_t width, uint32_t height, float fovy, Point<float> eye, Point<float> lookAt, Vec3f up)
    : mWidth(width)
    , mHeight(height)
    , mFovy(fovy)
    , mAspect((float)width / (float)height)
    , mEyePos(std::move(eye))
    , mLookAt(std::move(lookAt))
    , mUp(std::move(up))
    , mW((mEyePos - mLookAt).Normalize())
    , mU(mUp.Cross(mW).Normalize())
    , mV(mW.Cross(mU))
{
}

auto Camera::GenerateRay(std::pair<uint32_t, uint32_t> screenPixel) -> Ray<float>
{
    const auto [x, y] = screenPixel;
    const float halfWidth = mWidth / 2.0f;
    const float halfHeight = mHeight / 2.0f;
    const float fovyRad = Radians(mFovy);
    const float fovx = tan(fovyRad / 2.0f) * mAspect;
    const float alpha = tan(fovx / 2.0f) * ((((float)x + 0.5f) - halfWidth) / halfWidth) * 2.0f;
    const float beta = tan(fovyRad / 2.0f) * ((halfHeight - ((float)y + 0.5f)) / halfHeight);

    const auto dir = ((mU * alpha) + (mV * beta) - mW).Normalize();

    return Ray<float>(mEyePos, dir);
}

auto Camera::Width() const -> uint32_t
{
    return mWidth;
}

auto Camera::Height() const -> uint32_t
{
    return mHeight;
}
