#pragma once

#include <vector>
#include <string>

class Config
{
public:
    enum class Type
    {
        Size,
        Camera,
        Ambient,
        Directional,
        Point,
        Diffuse,
        Specular,
        MaxVertex,
        Vertex,
        Triangle
    };

public:
    static constexpr std::string_view CameraToken = "camera";
    static constexpr std::string_view SizeToken = "size";
    static constexpr std::string_view AmbientToken = "ambient";
    static constexpr std::string_view DirectionalToken = "directional";
    static constexpr std::string_view PointToken = "point";
    static constexpr std::string_view DiffuseToken = "diffuse";
    static constexpr std::string_view SpecularToken = "specular";
    static constexpr std::string_view MaxVertexToken = "maxverts";
    static constexpr std::string_view VertexToken = "vertex";
    static constexpr std::string_view TriangleToken = "tri";

public:
    Config(Type type, std::vector<float> params);
    auto GetType() const -> Type;
    auto GetParams() const -> const std::vector<float>&;

private:
    Type mType{};
    std::vector<float> mParameters{};
};