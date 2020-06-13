#pragma once

#include <glm\vec3.hpp>
#include "Config.hpp"

#include <utility>

struct Ray
{
public:
    constexpr Ray(glm::vec3 pos, glm::vec3 dir, float tMax = Config::TMax, float tMin = Config::TMin)
        : mOrigin(std::move(pos))
        , mDir(std::move(dir))
        , mTMax(tMax)
        , mTMin(tMin)
    {
    }

public:
    glm::vec3 mOrigin;
    glm::vec3 mDir;
    float mTMax;
    float mTMin;
};
