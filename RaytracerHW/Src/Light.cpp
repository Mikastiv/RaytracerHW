#include "Light.hpp"

Light::Light(glm::vec3 color)
    : mColor(std::move(color))
{
}
