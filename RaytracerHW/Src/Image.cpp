#include "Image.hpp"

#include <algorithm>
#include <OpenImageIO/imageio.h>

Image::Image(uint32_t width, uint32_t height)
    : mWidth(width)
    , mHeight(height)
    , pImage(std::make_unique<Color[]>((size_t)width * height))
{
}

auto Image::PutPixel(uint32_t x, uint32_t y, Color c) -> void
{
    pImage[(size_t)y * mWidth + x] = c;
}

auto Image::Save(std::string_view file) const -> bool
{
    std::unique_ptr<OIIO::ImageOutput> output = OIIO::ImageOutput::create(file.data());

    if (!output)
    {
        return false;
    }

    OIIO::ImageSpec spec(mWidth, mHeight, Color::ChannelCount, OIIO::TypeDesc::UINT8);
    output->open(file.data(), spec);
    output->write_image(OIIO::TypeDesc::UINT8, pImage.get());
    output->close();

    return true;
}

auto Image::Clear(Color c) -> void
{
    for (size_t y = 0; y < mHeight; y++)
    {
        for (size_t x = 0; x < mWidth; x++)
        {
            pImage[y * mWidth + x] = c;
        }
    }
}
