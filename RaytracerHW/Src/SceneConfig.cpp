#include "SceneConfig.hpp"

#include <stdexcept>
#include <sstream>

SceneConfig::SceneConfig(const std::vector<Config>& configs)
{
    using Type = Config::Type;

    for (const auto& c : configs)
    {
        const auto& params = c.GetParams();

        switch (c.GetType())
        {
        case Type::Size:
        {
            if (params.size() != Config::SizeParamCount)
                ThrowException(Config::SizeToken);

            mWidth = (uint32_t)std::get<float>(params[0]);
            mHeight = (uint32_t)std::get<float>(params[1]);
            break;
        }
        case Type::MaxDepth:
        {
            if (params.size() != Config::MaxDepthParamCount)
                ThrowException(Config::MaxDepthToken);

            mMaxRayDepth = (uint32_t)std::get<float>(params[0]);
            break;
        }
        case Type::Output:
        {
            if (params.size() != Config::OutputParamCount)
                ThrowException(Config::OutputToken);

            mFilename = std::get<std::string>(params[0]);
            break;
        }
        case Type::Camera:
        {
            if (params.size() != Config::CameraParamCount)
                ThrowException(Config::CameraToken);

            mEyePos = Vec3f{ std::get<float>(params[0]), std::get<float>(params[1]), std::get<float>(params[2]) };
            mLookAt = Vec3f{ std::get<float>(params[3]), std::get<float>(params[4]), std::get<float>(params[5]) };
            mUp = Vec3f{ std::get<float>(params[6]), std::get<float>(params[7]), std::get<float>(params[8]) };
            mUp.Normalize();
            mFovy = std::get<float>(params[9]);
            break;
        }
        default:
            break;
        }
    }
}

auto SceneConfig::GetWidth() const noexcept -> uint32_t
{
    return mWidth;
}

auto SceneConfig::GetHeight() const noexcept -> uint32_t
{
    return mHeight;
}

auto SceneConfig::GetMaxRayDepth() const noexcept -> uint32_t
{
    return mMaxRayDepth;
}

auto SceneConfig::GetFilename() const noexcept -> std::string
{
    return mFilename;
}

auto SceneConfig::GetEyePos() const noexcept -> Vec3f
{
    return mEyePos;
}

auto SceneConfig::GetLookAt() const noexcept -> Vec3f
{
    return mLookAt;
}

auto SceneConfig::GetUp() const noexcept -> Vec3f
{
    return mUp;
}

auto SceneConfig::GetFovy() const noexcept -> float
{
    return mFovy;
}

auto SceneConfig::ThrowException(std::string_view paramName) const -> void
{
    std::ostringstream oss{};
    oss << "Bad number of parameters for " << paramName;
    throw std::runtime_error(oss.str().c_str());
}
