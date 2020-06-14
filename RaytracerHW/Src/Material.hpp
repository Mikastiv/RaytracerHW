#pragma once

#include <glm\vec3.hpp>

struct Material
{
public:
    constexpr Material(glm::vec3 kd, glm::vec3 ks, glm::vec3 ka, glm::vec3 ke, float kr, float shininess)
        : mKd(kd)
        , mKs(ks)
        , mKa(ka)
        , mKe(ke)
        , mKr(kr)
        , mShininess(shininess)
    {
    }

public:
    glm::vec3 mKd;
    glm::vec3 mKs;
    glm::vec3 mKa;
    glm::vec3 mKe;
    float mKr;
    float mShininess;
};