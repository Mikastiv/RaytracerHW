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

                if (line != "" && line[0] != '#')
                {
                    std::string token{};
                    std::istringstream ss(line);

                    // Extract token
                    ss >> token;
                    token = ToLower(token);

                    // Values for the token
                    std::string values(line.substr(token.size()));

                    try
                    {
                        if (token == Config::CameraToken)
                        {
                            configs.push_back(ExtractParams(Config::Type::Camera, values));
                        }
                        else if (token == Config::SizeToken)
                        {
                            configs.push_back(ExtractParams(Config::Type::Size, values));
                        }
                        else if (token == Config::AmbientToken)
                        {
                            configs.push_back(ExtractParams(Config::Type::Ambient, values));
                        }
                        else if (token == Config::DirectionalToken)
                        {
                            configs.push_back(ExtractParams(Config::Type::Directional, values));
                        }
                        else if (token == Config::PointToken)
                        {
                            configs.push_back(ExtractParams(Config::Type::Point, values));
                        }
                        else if (token == Config::DiffuseToken)
                        {
                            configs.push_back(ExtractParams(Config::Type::Diffuse, values));
                        }
                        else if (token == Config::SpecularToken)
                        {
                            configs.push_back(ExtractParams(Config::Type::Specular, values));
                        }
                        else if (token == Config::MaxVertexToken)
                        {
                            configs.push_back(ExtractParams(Config::Type::MaxVertex, values));
                        }
                        else if (token == Config::VertexToken)
                        {
                            configs.push_back(ExtractParams(Config::Type::Vertex, values));
                        }
                        else if (token == Config::TriangleToken)
                        {
                            configs.push_back(ExtractParams(Config::Type::Triangle, values));
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
                            std::filesystem::path filePath(file);
                            error << "Bad parameter token at line " << lineNo << ", [File] "
                                  << std::filesystem::absolute(filePath);

                            return error.str();
                        };

                        throw std::runtime_error(CreateErrorStr(file, i).c_str());
                    }
                }
            }
        }
        else
        {
            const auto CreateErrorStr = [](std::string_view file) {
                std::ostringstream error{};
                std::filesystem::path filePath(file);
                error << "Could not open file " << std::filesystem::absolute(filePath);

                return error.str();
            };

            throw std::runtime_error(CreateErrorStr(file).c_str());
        }
    }

    return configs;
}

auto Parser::ExtractParams(Config::Type type, std::string_view line) -> Config
{
    std::istringstream ss(line.data());

    std::vector<float> params{};
    
    for (std::string value; ss >> value;)
    {
        params.push_back(std::stof(value));
    }

    return Config(type, std::move(params));
}
