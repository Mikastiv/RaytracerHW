#pragma once

#include "Color.hpp"

struct Material
{
public:
    Material(Color kd, Color ks, Color ka, Color kr)
        : mKd(kd)
        , mKs(ks)
        , mKa(ka)
        , mKr(kr)
    {
    }

public:
    Color mKd;
    Color mKs;
    Color mKa;
    Color mKr;
};