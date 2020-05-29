#pragma once

#include <string_view>
#include <algorithm>
#include <string>

constexpr float PI = 3.141592653f;

inline auto ToLower(std::string_view str) -> std::string
{
    std::string output(str.size(), '#');
    std::transform(str.cbegin(), str.cend(), output.begin(), [](auto c) { return std::tolower(c); });
    return output;
}

inline auto LTrim(std::string_view str) -> std::string
{
    size_t start = str.find_first_not_of(' ');
    std::string output((start != std::string::npos) ? str.substr(start) : "");
    return output;
}

inline auto Radians(float degrees) -> float
{
    return degrees * PI / 180.0f;
}