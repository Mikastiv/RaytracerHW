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

                    ss >> token;
                    token = ToLower(token);

                    try
                    {
                        if (token == Config::CameraToken)
                        {
                            configs.push_back(ExtractParams(Config::Type::Camera, line.substr(token.size())));
                        }
                        else if (token == Config::SizeToken)
                        {
                            configs.push_back(ExtractParams(Config::Type::Size, line.substr(token.size())));
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
