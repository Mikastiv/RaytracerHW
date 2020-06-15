#include <iostream>

#include "Parser.hpp"
#include "Scene.hpp"

int main(int argc, char* argv[])
{
    std::unique_ptr<Scene> scene = nullptr;

    try
    {
        if (argc < 2)
            throw std::runtime_error("No command file specified");

        std::cout << "Reading file...\n";
        const auto configs = Parser::ParseFile(argv[1]);
        const SceneConfig sceneConfig{ configs };
        std::cout << "Generating image...\n";
        scene = std::make_unique<Scene>(sceneConfig);
        scene->Render();
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

    system("pause");
}
