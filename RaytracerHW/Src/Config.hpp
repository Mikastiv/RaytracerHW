#pragma once

#include "Point.hpp"

#include <vector>
#include <string>
#include <variant>

class Config
{
public:
    enum class Type
    {
        Size,
        MaxDepth,
        Output,
        Camera,
        Sphere,
        MaxVertex,
        MaxVertexNorms,
        Vertex,
        VertexNormal,
        Triangle,
        TriangleNormal,
        Translate,
        Rotate,
        Scale,
        PushTransform,
        PopTransform,
        Directional,
        Point,
        Attenuation,
        Ambient,
        Diffuse,
        Specular,
        Shininess,
        Emission
    };

public:
    // clang-format off

    // Command Tokens
    static constexpr std::string_view SizeToken             = "size";
    static constexpr std::string_view MaxDepthToken         = "maxdepth";
    static constexpr std::string_view OutputToken           = "output";
    static constexpr std::string_view CameraToken           = "camera";
    static constexpr std::string_view SphereToken           = "sphere";
    static constexpr std::string_view MaxVertexToken        = "maxverts";
    static constexpr std::string_view MaxVertexNormalToken  = "maxvertnorms";
    static constexpr std::string_view VertexToken           = "vertex";
    static constexpr std::string_view VertexNormalToken     = "vertexnormal";
    static constexpr std::string_view TriangleToken         = "tri";
    static constexpr std::string_view TriangleNormalToken   = "trinormal";
    static constexpr std::string_view TranslateToken        = "translate";
    static constexpr std::string_view RotateToken           = "rotate";
    static constexpr std::string_view ScaleToken            = "scale";
    static constexpr std::string_view PushTransformToken    = "pushtransform";
    static constexpr std::string_view PopTransformToken     = "poptransform";
    static constexpr std::string_view DirectionalToken      = "directional";
    static constexpr std::string_view PointToken            = "point";
    static constexpr std::string_view AttenuationToken      = "attenuation";
    static constexpr std::string_view AmbientToken          = "ambient";
    static constexpr std::string_view DiffuseToken          = "diffuse";
    static constexpr std::string_view SpecularToken         = "specular";
    static constexpr std::string_view ShininessToken        = "shininess";
    static constexpr std::string_view EmissionToken         = "emission";
    // clang-format on

    // Command Param Count
    static constexpr uint8_t SizeParamCount = 2;
    static constexpr uint8_t MaxDepthParamCount = 1;
    static constexpr uint8_t OutputParamCount = 1;
    static constexpr uint8_t CameraParamCount = 10;

    // Default Values
    static constexpr std::string_view DefaultOutputFile = "output.png";
    static constexpr uint32_t DefaultWidth = 640;
    static constexpr uint32_t DefaultHeight = 480;
    static constexpr uint32_t DefaultMaxRayDepth = 5;
    static constexpr Point<float> DefaultEyePos = { 0.0f, 0.0f, 0.0f };
    static constexpr Point<float> DefaultLookAt = { 0.0f, 0.0f, 1.0f };
    static constexpr Vec3f DefaultUp = { 0.0f, 1.0f, 0.0f };
    static constexpr float DefaultFovy = 90.0f;

public:
    Config(Type type, std::vector<std::variant<float, std::string>> params);

    auto GetType() const -> Type;
    auto GetParams() const -> const std::vector<std::variant<float, std::string>>&;

private:
    Type mType{};
    std::vector<std::variant<float, std::string>> mParameters{};
};