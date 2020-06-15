#include "TriangleNormal.hpp"

TriangleNormal::TriangleNormal(
    Material material, glm::mat4 transform, std::pair<glm::vec3, glm::vec3> v0, std::pair<glm::vec3, glm::vec3> v1,
    std::pair<glm::vec3, glm::vec3> v2)
    : Triangle(std::move(material), std::move(transform), v0.first, v1.first, v2.first)
    , mV0n(v0.second)
    , mV1n(v1.second)
    , mV2n(v2.second)
{
}

auto TriangleNormal::Shade(
    const glm::vec3& lightDir, glm::vec3 lightColor, const LocalGeo& localGeo, const glm::vec3& halfVec) const
    -> glm::vec3
{
    return Shape::Shade(lightDir, lightColor, localGeo, halfVec);
}
