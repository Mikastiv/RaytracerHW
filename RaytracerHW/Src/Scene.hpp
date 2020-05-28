#pragma once

#include "SceneConfig.hpp"
#include "Sampler.hpp"
#include "Camera.hpp"
#include "Image.hpp"
#include "Point.hpp"

#include <vector>

class Scene
{
public:
    Scene(const SceneConfig& c);

    auto Render() -> void;

private:
    Sampler mSampler;
    Camera mCamera;
    Image mImage;
    std::string mOutputFile;
};