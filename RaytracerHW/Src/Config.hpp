#pragma once

#include <vector>
#include <string>

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
    //clang-format on

public:
    Config(Type type, std::vector<float> params);
    auto GetType() const -> Type;
    auto GetParams() const -> const std::vector<float>&;

private:
    Type mType{};
    std::vector<float> mParameters{};
};