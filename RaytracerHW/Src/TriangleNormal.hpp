#pragma once

#include "Triangle.hpp"

class TriangleNormal : public Triangle
{
public:
    TriangleNormal(
        Material material, glm::mat4 transform, std::pair<glm::vec3, glm::vec3> v0, std::pair<glm::vec3, glm::vec3> v1,
        std::pair<glm::vec3, glm::vec3> v2);

    auto
    Shade(const glm::vec3& lightDir, glm::vec3 lightColor, const LocalGeo& localGeo, const glm::vec3& halfVec) const
        -> glm::vec3 override;

private:
    glm::vec3 mV0n;
    glm::vec3 mV1n;
    glm::vec3 mV2n;
};