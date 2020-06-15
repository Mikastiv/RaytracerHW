#pragma once

#include "Config.hpp"
#include "Shape.hpp"
#include "PointLight.hpp"

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <stack>
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
    auto GetEyePos() const noexcept -> glm::vec3;
    auto GetLookAt() const noexcept -> glm::vec3;
    auto GetUp() const noexcept -> glm::vec3;
    auto GetFovy() const noexcept -> float;
    auto GetShapes() const -> std::vector<std::shared_ptr<Shape>>;
    auto GetLights() const -> std::vector<std::shared_ptr<Light>>;

private:
    auto ThrowParamCountException(std::string_view paramName, uint32_t lineNumber) const -> void;

private:
    uint32_t mWidth{ Config::DefaultWidth };
    uint32_t mHeight{ Config::DefaultHeight };
    uint32_t mMaxRayDepth{ Config::DefaultMaxRayDepth };
    uint32_t mMaxVertex{ Config::DefaultMaxVertex };
    uint32_t mMaxVertexNormal{ Config::DefaultMaxVertexNorms };
    std::string mFilename{ Config::DefaultOutputFile };
    glm::vec3 mEyePos{ Config::DefaultEyePos };
    glm::vec3 mLookAt{ Config::DefaultLookAt };
    glm::vec3 mUp{ Config::DefaultUp };
    float mFovy{ Config::DefaultFovy };
    Material mMaterial{ Config::DefaultMaterial };
    std::vector<glm::vec3> mVertices{};
    std::vector<std::pair<glm::vec3, glm::vec3>> mVerticesNormals{};
    std::vector<std::shared_ptr<Shape>> mShapes{};
    std::vector<std::shared_ptr<Light>> mLights{};
    PointLight::Attenuation mAttenuation{ Config::DefaultAttenuation.x,
                                          Config::DefaultAttenuation.y,
                                          Config::DefaultAttenuation.z };
    std::stack<glm::mat4> mMatrixStack{};
    glm::mat4 mTransform{1.0f};
};