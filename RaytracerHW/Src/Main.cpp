#include <iostream>

#include "Parser.hpp"
#include "Scene.hpp"

int main()
{
    const auto ReadConfigFile = [](std::string_view file) {
        std::vector<Config> c{};

        try
        {
            c = Parser::ParseFile(file);
        }
        catch (const std::runtime_error& e)
        {
            std::cerr << e.what() << '\n';
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        catch (...)
        {
            std::cerr << "Unhandled exception caught\n";
        }

        return c;
    };

    Scene scene{ ReadConfigFile("scene1.test") };
}
