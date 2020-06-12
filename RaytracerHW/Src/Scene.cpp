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
    uint8_t lastPercentage = 0;

    const float pixelPercentageDelta = 1.0f / float(mImage.GetWidth() * mImage.GetHeight());
    float percentage = pixelPercentageDelta;

    while (const auto pixel = mSampler.Sample())
    {
        const auto ray = mCamera.GenerateRay(*pixel);
        const auto [x, y] = *pixel;

        Color c = mRaytracer.Trace(ray, mCamera.GetEyePos());

        mImage.PutPixel(x, y, c);

        // 396 206
        // 390 220

        const uint32_t charCount = uint32_t(percentage * Config::ProgressBarSize);
        const uint32_t currentPercentage = uint32_t(percentage * 100);

        if (currentPercentage > lastPercentage)
        {
            std::cout << "\rProgress: |" << std::setw(Config::ProgressBarSize) << std::left
                      << std::string(charCount, '=') << "| " << currentPercentage << '%' << std::flush;
            lastPercentage = currentPercentage;
        }
        percentage += pixelPercentageDelta;
    }

    mImage.Save(mOutputFile);
}
