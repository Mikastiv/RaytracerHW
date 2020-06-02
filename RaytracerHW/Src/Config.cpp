#include "Config.hpp"

Config::Config(Type type, std::vector<std::variant<float, std::string>> params, uint32_t line)
    : mType(type)
    , mParameters(std::move(params))
    , mLine(line)
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

auto Config::GetLineNumber() const -> uint32_t
{
    return mLine;
}
