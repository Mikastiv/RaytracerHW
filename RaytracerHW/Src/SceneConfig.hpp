#pragma once

#include "Config.hpp"
#include "Vec3.hpp"
#include "Shape.hpp"

#include <memory>

class SceneConfig
{
public:
    SceneConfig() = default;
    SceneConfig(const std::vector<Config>& configs);

    auto GetWidth() const noexcept -> uint32_t;
    auto GetHeight() const noexcept -> uint32_t;
    auto GetMaxRayDepth() const noexcept -> uint32_t;
    auto GetFilename() const noexcept -> std::string;
    auto GetEyePos() const noexcept -> Vec3f;
    auto GetLookAt() const noexcept -> Vec3f;
    auto GetUp() const noexcept -> Vec3f;
    auto GetFovy() const noexcept -> float;
    auto GetShapes() const -> std::vector<std::shared_ptr<Shape>>;

private:
    auto ThrowParamCountException(std::string_view paramName) const -> void;

private:
    uint32_t mWidth{ Config::DefaultWidth };
    uint32_t mHeight{ Config::DefaultHeight };
    uint32_t mMaxRayDepth{ Config::DefaultMaxRayDepth };
    uint32_t mMaxVertex{ Config::DefaultMaxVertex };
    uint32_t mMaxVertexNormal{ Config::DefaultMaxVertexNorms };
    std::string mFilename{ Config::DefaultOutputFile };
    Vec3f mEyePos{ Config::DefaultEyePos };
    Vec3f mLookAt{ Config::DefaultLookAt };
    Vec3f mUp{ Config::DefaultUp };
    float mFovy{ Config::DefaultFovy };
    Material mMaterial{ Config::DefaultMaterial };
    std::vector<Vec3f> mVertices{};
    std::vector<Vec3f> mNormals{};
    std::vector<std::shared_ptr<Shape>> mShapes{};
};