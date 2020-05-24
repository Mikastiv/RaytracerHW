#include "Parser.hpp"

#include "Utils.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>

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
                    if (token == Config::CameraToken)
                    {
                        configs.push_back(ExtractParams(Config::Type::Camera, line.substr(token.size())));
                    }
                    else if (token == Config::SizeToken)
                    {

                    }
                    else
                    {
                        std::ostringstream error{};
                        error << "Bad parameter token at line " << i;
                        throw std::runtime_error(error.str().c_str());
                    }
                }
            }
        }
    }

    return std::vector<Config>();
}

auto Parser::ExtractParams(Config::Type type, std::string_view line) -> Config
{
    std::istringstream ss(line.data());

    std::vector<float> params{};
    float value = 0.0f;
    while (ss >> value)
    {
        params.push_back(value);
    }

    return Config(type, std::move(params));
}
