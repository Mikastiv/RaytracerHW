#include "Scene.hpp"

#include "Sphere.hpp"

Scene::Scene(const SceneConfig& c)
    : mSampler(c.GetWidth(), c.GetHeight())
    , mCamera(c.GetWidth(), c.GetHeight(), c.GetFovy(), c.GetEyePos(), c.GetLookAt(), c.GetUp())
    , mImage(c.GetWidth(), c.GetHeight())
    , mOutputFile(c.GetFilename())
{
}

auto Scene::Render() -> void
{
    Sphere sphere{ {0,0,0}, 0.75f };
    while (const auto pixel = mSampler.Sample())
    {
        const auto ray = mCamera.GenerateRay(*pixel);
        const auto [x, y] = *pixel;
        
        const auto i = sphere.Intersect(ray);

        mImage.PutPixel(x, y, i ? Color{ 255, 255, 0 } : Color{ 0, 0, 0 });
    }

    mImage.Save(mOutputFile);
}
