#pragma once

#include "Color.hpp"

struct Material
{
public:
    constexpr Material(Color kd, Color ks, Color ka, Color ke, uint32_t shininess)
        : mKd(kd)
        , mKs(ks)
        , mKa(ka)
        , mKe(ke)
        , mShininess(shininess)
    {
    }

public:
    Color mKd;
    Color mKs;
    Color mKa;
    Color mKe;
    uint32_t mShininess;
};