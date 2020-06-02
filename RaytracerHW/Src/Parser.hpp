#pragma once

#include "Config.hpp"

#include <string_view>

class Parser
{
public:
    static auto ParseFile(std::string_view file) -> std::vector<Config>;

private:
    static auto ExtractParams(Config::Type type, std::string_view line, uint32_t lineNumber) -> Config;
};