#pragma once

#include "Camera.hpp"
#include "Point.hpp"

class Scene
{
private:
    Point<float> mEye{};
    Camera mCamera{};
};