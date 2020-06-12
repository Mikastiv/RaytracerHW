#include <iostream>

#include "Parser.hpp"
#include "Scene.hpp"

int main()
{
    std::unique_ptr<Scene> scene = nullptr;

    try
    {
        const auto configs = Parser::ParseFile("scene1.test");
        const SceneConfig sceneConfig{ configs };
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
}
