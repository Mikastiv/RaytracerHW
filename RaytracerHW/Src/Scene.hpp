#pragma once

#include "Config.hpp"
#include "Sampler.hpp"
#include "Camera.hpp"
#include "Point.hpp"

#include <vector>

class Scene
{
public:
    Scene() = default;
    Scene(const std::vector<Config>& configs);

private:
    Sampler mSampler{};
    Camera mCamera{};
};