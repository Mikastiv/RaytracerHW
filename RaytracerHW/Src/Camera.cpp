#include "Camera.hpp"

Camera::Camera(uint32_t width, uint32_t height, float fovy, Point<float> eye, Point<float> lookAt, Vec3f up)
    : mWidth(width)
    , mHeight(height)
    , mFovy(fovy)
    , mAspect((float)width / (float)height)
    , mEyePos(std::move(eye))
    , mLookAt(std::move(lookAt))
    , mUp(std::move(up))
{
}

auto Camera::GenerateRay(std::pair<uint32_t, uint32_t> screenPixel) -> Ray<float>
{
    const auto w = (mEyePos - mLookAt).Normalize();
    const auto u = mUp.Cross(w).Normalize();
    const auto v = w.Cross(u);

    const auto [x, y] = screenPixel;
    const auto halfWidth = mWidth / 2.0f;
    const auto halfHeight = mHeight / 2.0f;
    const auto tanFovy = tan(mFovy / 2.0f);
    const auto alpha = tanFovy * mAspect * (((y + 0.5f) - halfWidth) / halfWidth);
    const auto beta = tanFovy * ((halfHeight - (x + 0.5f)) / halfHeight);
    // const auto fovx = 2.0f * atan(tan(mFovy / 2.0f) * mAspect);
    // const auto alpha = tan(fovx / 2.0f) * (((y + 0.5f) - halfWidth) / halfWidth);
    // const auto beta = tanFovy * ((halfHeight - (x + 0.5f)) / halfHeight);

    const auto dir = ((alpha * u) + (beta * v) - w).Normalize();

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
