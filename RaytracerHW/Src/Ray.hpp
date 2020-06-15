#pragma once

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
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

    constexpr auto operator*(const glm::mat4& mat) const -> Ray
    {
        return Ray{ glm::vec3(mat * glm::vec4(mOrigin, 1.0f)),
                    glm::normalize(glm::vec3(mat * glm::vec4(mDir, 0.0f))) };
    }

    constexpr friend auto operator*(glm::mat4 mat, const Ray& ray) -> Ray
    {
        return ray * mat;
    }

public:
    glm::vec3 mOrigin;
    glm::vec3 mDir;
    float mTMax;
    float mTMin;
};
