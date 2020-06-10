#include "Parser.hpp"

#include "Utils.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <filesystem>

auto Parser::ParseFile(std::string_view file) -> std::vector<Config>
{
    std::vector<Config> configs{};
    {
        std::ifstream inputFile(file.data());

        if (inputFile.is_open())
        {
            std::string line{};
            for (int i = 1; std::getline(inputFile, line); i++)
            {
                line = LTrim(line);

                // Empty line or comment
                if (line == "" || line[0] == '#')
                {
                    continue;
                }

                std::string token{};
                std::istringstream ss(line);

                // Extract token
                ss >> token;
                token = ToLower(token);

                // Values for the token
                std::string values(line.substr(token.size()));

                try
                {
                    if (token == Config::SizeToken)
                    {
                        configs.push_back(ExtractParams(Config::Type::Size, values, i));
                    }
                    else if (token == Config::MaxDepthToken)
                    {
                        configs.push_back(ExtractParams(Config::Type::MaxDepth, values, i));
                    }
                    else if (token == Config::OutputToken)
                    {
                        configs.push_back(ExtractParams(Config::Type::Output, values, i));
                    }
                    else if (token == Config::CameraToken)
                    {
                        configs.push_back(ExtractParams(Config::Type::Camera, values, i));
                    }
                    else if (token == Config::SphereToken)
                    {
                        configs.push_back(ExtractParams(Config::Type::Sphere, values, i));
                    }
                    else if (token == Config::MaxVertexToken)
                    {
                        configs.push_back(ExtractParams(Config::Type::MaxVertex, values, i));
                    }
                    else if (token == Config::MaxVertexNormalToken)
                    {
                        configs.push_back(ExtractParams(Config::Type::MaxVertexNorms, values, i));
                    }
                    else if (token == Config::VertexToken)
                    {
                        configs.push_back(ExtractParams(Config::Type::Vertex, values, i));
                    }
                    else if (token == Config::VertexNormalToken)
                    {
                        configs.push_back(ExtractParams(Config::Type::VertexNormal, values, i));
                    }
                    else if (token == Config::TriangleToken)
                    {
                        configs.push_back(ExtractParams(Config::Type::Triangle, values, i));
                    }
                    else if (token == Config::TriangleNormalToken)
                    {
                        configs.push_back(ExtractParams(Config::Type::TriangleNormal, values, i));
                    }
                    else if (token == Config::TranslateToken)
                    {
                        configs.push_back(ExtractParams(Config::Type::Translate, values, i));
                    }
                    else if (token == Config::RotateToken)
                    {
                        configs.push_back(ExtractParams(Config::Type::Rotate, values, i));
                    }
                    else if (token == Config::ScaleToken)
                    {
                        configs.push_back(ExtractParams(Config::Type::Scale, values, i));
                    }
                    else if (token == Config::PushTransformToken)
                    {
                        configs.push_back(ExtractParams(Config::Type::PushTransform, values, i));
                    }
                    else if (token == Config::PopTransformToken)
                    {
                        configs.push_back(ExtractParams(Config::Type::PopTransform, values, i));
                    }
                    else if (token == Config::DirectionalLightToken)
                    {
                        configs.push_back(ExtractParams(Config::Type::DirectionalLight, values, i));
                    }
                    else if (token == Config::PointLightToken)
                    {
                        configs.push_back(ExtractParams(Config::Type::PointLight, values, i));
                    }
                    else if (token == Config::AttenuationToken)
                    {
                        configs.push_back(ExtractParams(Config::Type::Attenuation, values, i));
                    }
                    else if (token == Config::AmbientToken)
                    {
                        configs.push_back(ExtractParams(Config::Type::Ambient, values, i));
                    }
                    else if (token == Config::DiffuseToken)
                    {
                        configs.push_back(ExtractParams(Config::Type::Diffuse, values, i));
                    }
                    else if (token == Config::SpecularToken)
                    {
                        configs.push_back(ExtractParams(Config::Type::Specular, values, i));
                    }
                    else if (token == Config::ShininessToken)
                    {
                        configs.push_back(ExtractParams(Config::Type::Shininess, values, i));
                    }
                    else if (token == Config::EmissionToken)
                    {
                        configs.push_back(ExtractParams(Config::Type::Emission, values, i));
                    }
                    else
                    {
                        throw std::invalid_argument("");
                    }
                }
                catch (const std::invalid_argument&)
                {
                    const auto CreateErrorStr = [](std::string_view file, int lineNo) {
                        std::ostringstream error{};
                        error << "Bad command token at line " << lineNo
                              << ", [File: " << std::filesystem::absolute(file) << ']';

                        return error.str();
                    };

                    throw std::runtime_error(CreateErrorStr(file, i).c_str());
                }
            }
        }
        else
        {
            const auto CreateErrorStr = [](std::string_view file) {
                std::ostringstream error{};
                error << "Could not open file " << std::filesystem::absolute(file);

                return error.str();
            };

            throw std::runtime_error(CreateErrorStr(file).c_str());
        }
    }

    return configs;
}

auto Parser::ExtractParams(Config::Type type, std::string_view line, uint32_t lineNumber) -> Config
{
    std::istringstream ss(line.data());

    std::vector<std::variant<float, std::string>> params{};

    for (std::string value; ss >> value;)
    {
        if (type == Config::Type::Output)
        {
            params.push_back(std::variant<float, std::string>{ value });
        }
        else
        {
            params.push_back(std::variant<float, std::string>{ std::stof(value) });
        }
    }

    return Config(type, std::move(params), lineNumber);
}
