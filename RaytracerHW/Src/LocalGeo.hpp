#pragma once

#include <glm\glm.hpp>

#include <utility>

struct LocalGeo
{
public:
    LocalGeo(glm::vec3 pos, glm::vec3 normal, float hitDistance)
        : mPos(pos)
        , mNormal(glm::normalize(normal))
        , mHitDistance(hitDistance)
    {
    }

public:
    glm::vec3 mPos;
    glm::vec3 mNormal;
    float mHitDistance;
};