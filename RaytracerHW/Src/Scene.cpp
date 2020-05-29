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

        const auto center = Point<float>{ 0.0f, 0.0f, 0.0f };
        const float radius = 0.5f;
        const auto oc = ray.mOrigin - center;
        const float a = Dot(ray.mDir, ray.mDir);
        const float b = 2.0f * Dot(ray.mDir, oc);
        const float c = Dot(oc, oc) - (radius * radius);

        const float discriminant = (b * b) - (4 * a * c);

        Color col{ 0, 0, 0 };

        if (!(discriminant < 0.0f))
        {
            const float sqDisc = sqrtf(discriminant);
            const float solution1 = (-b + sqDisc) / (2 * a);
            const float solution2 = (-b - sqDisc) / (2 * a);

            col = { 255, 0, 0 };
        }

        mImage.PutPixel(x, y, col);
    }

    mImage.Save(mOutputFile);
}
