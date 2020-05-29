#pragma once

#include "Primitive.hpp"
#include "LocalGeo.hpp"

struct Intersection
{
public:
    Intersection(Primitive& primitive, LocalGeo localGeo)
        : mPrimitive(primitive)
        , mLocalGeo(std::move(localGeo))
    {
    }

public:
    Primitive& mPrimitive;
    LocalGeo mLocalGeo;
};