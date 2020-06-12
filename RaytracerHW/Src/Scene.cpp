#include "Scene.hpp"

#include "Sphere.hpp"
#include "Triangle.hpp"

#include <iostream>
#include <iomanip>
#include <string>

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
    const uint32_t progressBarSize = 40;
    uint32_t lastCharCount = 0;

    while (const auto pixel = mSampler.Sample())
    {
        const auto ray = mCamera.GenerateRay(*pixel);
        const auto [x, y] = *pixel;

        Color c = mRaytracer.Trace(ray, mCamera.GetEyePos());

        mImage.PutPixel(x, y, c);

        const uint32_t currentPixel = y * mImage.GetWidth() + x;
        const float imagePixelSize = float(mImage.GetWidth() * mImage.GetHeight());
        const uint32_t charCount = uint32_t((currentPixel / imagePixelSize) * (progressBarSize + 1));

        if (charCount > lastCharCount)
        {
            std::cout << "\rProgress: " << std::setw(progressBarSize) << std::left << std::string(charCount, '=') << '|'
                      << std::flush;
            lastCharCount = charCount;
        }
    }

    mImage.Save(mOutputFile);
}
