#pragma once

#include <vector>
#include <string>

class Config
{
public:
    enum class Type
    {
        Camera
    };

public:
    static constexpr std::string_view CameraToken = "camera";
    static constexpr std::string_view SizeToken = "size";

public:
    Config(Type type, std::vector<float> params);
    auto GetType() const -> Type;
    auto GetParams() const -> const std::vector<float>&;

private:
    Type mType{};
    std::vector<float> mParameters{};
};