#pragma once

#include "Vec3.hpp"

struct Material
{
public:
    constexpr Material(Vec3f kd, Vec3f ks, Vec3f ka, Vec3f ke, float shininess)
        : mKd(kd)
        , mKs(ks)
        , mKa(ka)
        , mKe(ke)
        , mShininess(shininess)
    {
    }

public:
    Vec3f mKd;
    Vec3f mKs;
    Vec3f mKa;
    Vec3f mKe;
    float mShininess;
};