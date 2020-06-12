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
    uint32_t lastPercentage = 0;

    const float pixelPercentageDelta = 1.0f / float(mImage.GetWidth() * mImage.GetHeight());
    float percentage = pixelPercentageDelta;

    while (const auto pixel = mSampler.Sample())
    {
        const auto ray = mCamera.GenerateRay(*pixel);
        const auto [x, y] = *pixel;

        Color c = mRaytracer.Trace(ray, mCamera.GetEyePos());

        mImage.PutPixel(x, y, c);

        const uint32_t currentPixel = y * mImage.GetWidth() + x;
        const uint32_t charCount = uint32_t(percentage * progressBarSize);
        const uint32_t currentPercentage = uint32_t(percentage * 100);

        if (currentPercentage > lastPercentage)
        {
            std::cout << "\rProgress: |" << std::setw(progressBarSize) << std::left << std::string(charCount, '=')
                      << "| " << currentPercentage << '%' << std::flush;
            lastPercentage = currentPercentage;
        }
        percentage += pixelPercentageDelta;
    }

    mImage.Save(mOutputFile);
}
