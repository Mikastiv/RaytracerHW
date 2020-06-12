#include "Scene.hpp"

#include "Sphere.hpp"
#include "Triangle.hpp"

Scene::Scene(const SceneConfig& c)
    : mSampler(c.GetWidth(), c.GetHeight())
    , mCamera(c.GetWidth(), c.GetHeight(), c.GetFovy(), c.GetEyePos(), c.GetLookAt(), c.GetUp())
    , mImage(c.GetWidth(), c.GetHeight())
    , mOutputFile(c.GetFilename())
    , mRaytracer(c.GetShapes(), c.GetLights())
{
}

auto Scene::Render() -> void
{
    while (const auto pixel = mSampler.Sample())
    {
        const auto ray = mCamera.GenerateRay(*pixel);
        const auto [x, y] = *pixel;

        Color c = mRaytracer.Trace(ray, mCamera.GetEyePos());

        mImage.PutPixel(x, y, c);
    }

    mImage.Save(mOutputFile);
}
