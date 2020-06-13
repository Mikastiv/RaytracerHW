#include "Light.hpp"

Light::Light(Vec3f color)
    : mColor(std::move(color))
{
}
