#include "Light.hpp"

Light::Light(Color color)
    : mColor(std::move(color))
{
}
