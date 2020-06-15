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

    auto operator*(const glm::mat4& mat) const -> LocalGeo
    {
        return LocalGeo{ glm::vec3(mat * glm::vec4(mPos, 1.0f)),
                         glm::normalize(glm::vec3(glm::transpose(glm::inverse(mat)) * glm::vec4(mNormal, 0.0f))),
                         mHitDistance };
    }

    friend auto operator*(const glm::mat4& mat, const LocalGeo& local) -> LocalGeo
    {
        return local * mat;
    }

public:
    glm::vec3 mPos;
    glm::vec3 mNormal;
    float mHitDistance;
};