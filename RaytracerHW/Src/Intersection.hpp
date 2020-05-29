#pragma once

#include "LocalGeo.hpp"
#include "Primitive.hpp"

struct Intersection
{
public:
    Intersection(LocalGeo localGeo, Primitive* primitive)
        : mLocalGeo(std::move(localGeo))
        , mPrimitive(primitive)
    {
    }

public:
    LocalGeo mLocalGeo;
    Primitive* mPrimitive = nullptr;
};