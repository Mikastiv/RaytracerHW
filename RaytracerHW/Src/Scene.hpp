#pragma once

#include "SceneConfig.hpp"
#include "Sampler.hpp"
#include "Camera.hpp"
#include "Point.hpp"

#include <vector>

class Scene
{
public:
    Scene() = default;
    Scene(const SceneConfig& c);

private:
    Sampler mSampler{};
    Camera mCamera{};
};