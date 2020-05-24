#include "Config.hpp"

Config::Config(Type type, std::vector<float> params)
    : mType(type)
    , mParameters(std::move(params))
{
}

auto Config::GetType() const -> Type
{
    return mType;
}

auto Config::GetParams() const -> const std::vector<float>&
{
    return mParameters;
}
