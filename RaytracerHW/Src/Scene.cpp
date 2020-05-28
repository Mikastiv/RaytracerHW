#include "Scene.hpp"

Scene::Scene(const SceneConfig& c)
    : mSampler(c.GetWidth(), c.GetHeight())
    , mCamera(c.GetWidth(), c.GetHeight(), c.GetFovy(), c.GetEyePos(), c.GetLookAt(), c.GetUp())
    , mImage(c.GetWidth(), c.GetHeight())
    , mOutputFile(c.GetFilename())
{
}

auto Scene::Render() -> void
{
    while (const auto pixel = mSampler.Sample())
    {
        const auto ray = mCamera.GenerateRay(*pixel);
        const auto [x, y] = *pixel;

        mImage.PutPixel(x, y, { 255, 0, 0 });
    }

    mImage.Save(mOutputFile);
}
