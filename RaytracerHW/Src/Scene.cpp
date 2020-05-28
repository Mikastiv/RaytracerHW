#include "Scene.hpp"

Scene::Scene(const SceneConfig& c)
    : mSampler(c.GetWidth(), c.GetHeight())
    , mCamera(c.GetWidth(), c.GetHeight(), c.GetFovy(), c.GetEyePos(), c.GetLookAt(), c.GetUp())
{
}
