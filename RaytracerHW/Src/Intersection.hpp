#pragma once

#include "LocalGeo.hpp"

class Shape;

struct Intersection
{
public:
    Intersection(const Shape& shape, LocalGeo localGeo)
        : mShape(shape)
        , mLocalGeo(std::move(localGeo))
    {
    }

public:
    const Shape& mShape;
    LocalGeo mLocalGeo;
};