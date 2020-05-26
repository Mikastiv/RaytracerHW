#pragma once

#include "Color.hpp"

#include <memory>
#include <string_view>

class Image
{
public:
    Image(uint32_t width, uint32_t height);

    auto PutPixel(uint32_t x, uint32_t y, Color c) -> void;
    auto Save(std::string_view file) const -> bool;
    auto Clear(Color c) -> void;

private:
    uint32_t mWidth = 0;
    uint32_t mHeight = 0;
    std::unique_ptr<Color[]> pImage = nullptr;
};