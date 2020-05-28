#include "Config.hpp"

Config::Config(Type type, std::vector<std::variant<float, std::string>> params)
    : mType(type)
    , mParameters(std::move(params))
{
}

auto Config::GetType() const -> Type
{
    return mType;
}

auto Config::GetParams() const -> const std::vector<std::variant<float, std::string>>&
{
    return mParameters;
}
