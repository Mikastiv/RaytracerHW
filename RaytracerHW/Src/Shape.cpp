#include "Shape.hpp"

#include <glm\glm.hpp>
#include <algorithm>
#include <cmath>

auto Shape::Shade(const glm::vec3& lightDir, glm::vec3 lightColor, const LocalGeo& localGeo, const glm::vec3& halfVec)
    const -> glm::vec3
{
    const float nDotL = glm::dot(localGeo.mNormal, lightDir);
    const glm::vec3 lambert = mMaterial.mKd * lightColor * std::max(nDotL, 0.0f);

    const float nDotH = glm::dot(localGeo.mNormal, halfVec);
    const glm::vec3 phong = mMaterial.mKs * lightColor * std::pow(std::max(nDotH, 0.0f), mMaterial.mShininess);

    return lambert + phong;
}
