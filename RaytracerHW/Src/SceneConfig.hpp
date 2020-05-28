#pragma once

#include "Config.hpp"
#include "Point.hpp"

class SceneConfig
{
public:
    SceneConfig(const std::vector<Config>& configs);

    auto GetWidth() const noexcept -> uint32_t;
    auto GetHeight() const noexcept -> uint32_t;
    auto GetMaxRayDepth() const noexcept -> uint32_t;
    auto GetFilename() const noexcept -> std::string;
    auto GetEyePos() const noexcept -> Point<float>;
    auto GetLookAt() const noexcept -> Point<float>;
    auto GetUp() const noexcept -> Vec3f;
    auto GetFovy() const noexcept -> float;

private:
    auto ThrowException(std::string_view paramName) const -> void;

private:
    uint32_t mWidth{ Config::DefaultWidth };
    uint32_t mHeight{ Config::DefaultHeight };
    uint32_t mMaxRayDepth{ Config::DefaultMaxRayDepth };
    std::string mFilename{ Config::DefaultOutputFile };
    Point<float> mEyePos{ Config::DefaultEyePos };
    Point<float> mLookAt{ Config::DefaultLookAt };
    Vec3f mUp{ Config::DefaultUp };
    float mFovy{ Config::DefaultFovy };
};