#include "SceneConfig.hpp"

#include "Sphere.hpp"
#include "TriangleNormal.hpp"
#include "DirectionalLight.hpp"
#include "Color.hpp"

#include <stdexcept>
#include <sstream>

SceneConfig::SceneConfig(const std::vector<Config>& configs)
{
    using Type = Config::Type;

    for (const auto& c : configs)
    {
        const auto& params = c.GetParams();

        switch (c.GetType())
        {
        case Type::Size:
        {
            if (params.size() != Config::SizeParamCount)
                ThrowParamCountException(Config::SizeToken, c.GetLineNumber());

            mWidth = (uint32_t)std::get<float>(params[0]);
            mHeight = (uint32_t)std::get<float>(params[1]);
            break;
        }
        case Type::MaxDepth:
        {
            if (params.size() != Config::MaxDepthParamCount)
                ThrowParamCountException(Config::MaxDepthToken, c.GetLineNumber());

            mMaxRayDepth = (uint32_t)std::get<float>(params[0]);
            break;
        }
        case Type::MaxVertex:
        {
            if (params.size() != Config::MaxVertexParamCount)
                ThrowParamCountException(Config::MaxVertexToken, c.GetLineNumber());

            mMaxVertex = (uint32_t)std::get<float>(params[0]);
            break;
        }
        case Type::MaxVertexNorms:
        {
            if (params.size() != Config::MaxVertexNormalParamCount)
                ThrowParamCountException(Config::MaxVertexNormalToken, c.GetLineNumber());

            mMaxVertexNormal = (uint32_t)std::get<float>(params[0]);
            break;
        }
        case Type::Output:
        {
            if (params.size() != Config::OutputParamCount)
                ThrowParamCountException(Config::OutputToken, c.GetLineNumber());

            mFilename = std::get<std::string>(params[0]);
            break;
        }
        case Type::Camera:
        {
            if (params.size() != Config::CameraParamCount)
                ThrowParamCountException(Config::CameraToken, c.GetLineNumber());

            mEyePos = glm::vec3{ std::get<float>(params[0]), std::get<float>(params[1]), std::get<float>(params[2]) };
            mLookAt = glm::vec3{ std::get<float>(params[3]), std::get<float>(params[4]), std::get<float>(params[5]) };
            mUp = glm::vec3{ std::get<float>(params[6]), std::get<float>(params[7]), std::get<float>(params[8]) };
            mUp = glm::normalize(mUp);
            mFovy = std::get<float>(params[9]);
            break;
        }
        case Type::Sphere:
        {
            if (params.size() != Config::SphereParamCount)
                ThrowParamCountException(Config::SphereToken, c.GetLineNumber());

            mShapes.push_back(std::make_unique<Sphere>(
                mMaterial,
                mTransform,
                glm::vec3{ std::get<float>(params[0]), std::get<float>(params[1]), std::get<float>(params[2]) },
                std::get<float>(params[3])));
            break;
        }
        case Type::Vertex:
        {
            if (params.size() != Config::VertexParamCount)
                ThrowParamCountException(Config::VertexToken, c.GetLineNumber());

            if (mVertices.size() >= mMaxVertex)
                throw std::runtime_error("Too many vertices (max vertex param exceeded)");

            mVertices.emplace_back(std::get<float>(params[0]), std::get<float>(params[1]), std::get<float>(params[2]));
            break;
        }
        case Type::VertexNormal:
        {
            if (params.size() != Config::VertexNormalParamCount)
                ThrowParamCountException(Config::VertexNormalToken, c.GetLineNumber());

            if (mVerticesNormals.size() >= mMaxVertexNormal)
                throw std::runtime_error("Too many vertices with normals (max vertex normal param exceeded)");

            mVerticesNormals.push_back(std::make_pair(
                glm::vec3{ std::get<float>(params[0]), std::get<float>(params[1]), std::get<float>(params[2]) },
                glm::normalize(
                    glm::vec3{ std::get<float>(params[3]), std::get<float>(params[4]), std::get<float>(params[5]) })));
            break;
        }
        case Type::Triangle:
        {
            if (params.size() != Config::TriangleParamCount)
                ThrowParamCountException(Config::TriangleToken, c.GetLineNumber());

            mShapes.push_back(std::make_unique<Triangle>(
                mMaterial,
                mTransform,
                mVertices[(size_t)std::get<float>(params[0])],
                mVertices[(size_t)std::get<float>(params[1])],
                mVertices[(size_t)std::get<float>(params[2])]));
            break;
        }
        case Type::TriangleNormal:
        {
            if (params.size() != Config::TriangleParamCount)
                ThrowParamCountException(Config::TriangleNormalToken, c.GetLineNumber());

            mShapes.push_back(std::make_unique<TriangleNormal>(
                mMaterial,
                mTransform,
                mVerticesNormals[(size_t)std::get<float>(params[0])],
                mVerticesNormals[(size_t)std::get<float>(params[1])],
                mVerticesNormals[(size_t)std::get<float>(params[2])]));
            break;
        }
        case Type::DirectionalLight:
        {
            if (params.size() != Config::LightParamCount)
                ThrowParamCountException(Config::DirectionalLightToken, c.GetLineNumber());

            mLights.push_back(std::make_shared<DirectionalLight>(
                glm::vec3{ std::get<float>(params[3]), std::get<float>(params[4]), std::get<float>(params[5]) },
                glm::vec3{ std::get<float>(params[0]), std::get<float>(params[1]), std::get<float>(params[2]) }));
            break;
        }
        case Type::PointLight:
        {
            if (params.size() != Config::LightParamCount)
                ThrowParamCountException(Config::PointLightToken, c.GetLineNumber());

            mLights.push_back(std::make_shared<PointLight>(
                glm::vec3{ std::get<float>(params[3]), std::get<float>(params[4]), std::get<float>(params[5]) },
                glm::vec3{ std::get<float>(params[0]), std::get<float>(params[1]), std::get<float>(params[2]) },
                mAttenuation));
            break;
        }
        case Type::Ambient:
        {
            if (params.size() != Config::AmbientParamCount)
                ThrowParamCountException(Config::AmbientToken, c.GetLineNumber());

            mMaterial.mKa =
                glm::vec3{ std::get<float>(params[0]), std::get<float>(params[1]), std::get<float>(params[2]) };
            break;
        }
        case Type::Diffuse:
        {
            if (params.size() != Config::DiffuseParamCount)
                ThrowParamCountException(Config::DiffuseToken, c.GetLineNumber());

            mMaterial.mKd =
                glm::vec3{ std::get<float>(params[0]), std::get<float>(params[1]), std::get<float>(params[2]) };
            break;
        }
        case Type::Specular:
        {
            if (params.size() != Config::SpecularParamCount)
                ThrowParamCountException(Config::SpecularToken, c.GetLineNumber());

            mMaterial.mKs =
                glm::vec3{ std::get<float>(params[0]), std::get<float>(params[1]), std::get<float>(params[2]) };
            break;
        }
        case Type::Reflection:
        {
            if (params.size() != Config::ReflectionParamCount)
                ThrowParamCountException(Config::ReflectionToken, c.GetLineNumber());

            mMaterial.mKr = std::get<float>(params[0]);
            break;
        }
        case Type::Emission:
        {
            if (params.size() != Config::EmissionParamCount)
                ThrowParamCountException(Config::EmissionToken, c.GetLineNumber());

            mMaterial.mKe =
                glm::vec3{ std::get<float>(params[0]), std::get<float>(params[1]), std::get<float>(params[2]) };
            break;
        }
        case Type::Shininess:
        {
            if (params.size() != Config::ShininessParamCount)
                ThrowParamCountException(Config::ShininessToken, c.GetLineNumber());

            mMaterial.mShininess = std::get<float>(params[0]);
            break;
        }
        case Type::Attenuation:
        {
            if (params.size() != Config::AttenuationParamCount)
                ThrowParamCountException(Config::AttenuationToken, c.GetLineNumber());

            mAttenuation = { std::get<float>(params[0]), std::get<float>(params[1]), std::get<float>(params[2]) };
            break;
        }
        case Type::PushTransform:
        {
            mMatrixStack.push(mTransform);
            break;
        }
        case Type::PopTransform:
        {
            mTransform = mMatrixStack.top();
            mMatrixStack.pop();
            break;
        }
        case Type::Rotate:
        {
            if (params.size() != Config::RotationParamCount)
                ThrowParamCountException(Config::RotateToken, c.GetLineNumber());

            mTransform = glm::rotate(
                mTransform,
                std::get<float>(params[3]),
                glm::vec3{ std::get<float>(params[0]), std::get<float>(params[1]), std::get<float>(params[2]) });
            break;
        }
        case Type::Scale:
        {
            if (params.size() != Config::ScaleParamCount)
                ThrowParamCountException(Config::ScaleToken, c.GetLineNumber());

            mTransform = glm::scale(
                mTransform,
                glm::vec3{ std::get<float>(params[0]), std::get<float>(params[1]), std::get<float>(params[2]) });
            break;
        }
        case Type::Translate:
        {
            if (params.size() != Config::TranslationParamCount)
                ThrowParamCountException(Config::TranslateToken, c.GetLineNumber());

            mTransform = glm::translate(
                mTransform,
                glm::vec3{ std::get<float>(params[0]), std::get<float>(params[1]), std::get<float>(params[2]) });
            break;
        }
        default:
            break;
        }
    }
}

auto SceneConfig::GetWidth() const noexcept -> uint32_t
{
    return mWidth;
}

auto SceneConfig::GetHeight() const noexcept -> uint32_t
{
    return mHeight;
}

auto SceneConfig::GetMaxRayDepth() const noexcept -> uint32_t
{
    return mMaxRayDepth;
}

auto SceneConfig::GetFilename() const noexcept -> std::string
{
    return mFilename;
}

auto SceneConfig::GetEyePos() const noexcept -> glm::vec3
{
    return mEyePos;
}

auto SceneConfig::GetLookAt() const noexcept -> glm::vec3
{
    return mLookAt;
}

auto SceneConfig::GetUp() const noexcept -> glm::vec3
{
    return mUp;
}

auto SceneConfig::GetFovy() const noexcept -> float
{
    return mFovy;
}

auto SceneConfig::GetShapes() const -> std::vector<std::shared_ptr<Shape>>
{
    return mShapes;
}

auto SceneConfig::GetLights() const -> std::vector<std::shared_ptr<Light>>
{
    return mLights;
}

auto SceneConfig::ThrowParamCountException(std::string_view paramName, uint32_t lineNumber) const -> void
{
    std::ostringstream oss{};
    oss << "Bad number of parameters for " << paramName << " [Line: " << lineNumber << ']';
    throw std::runtime_error(oss.str().c_str());
}
