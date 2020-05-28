#include <iostream>

#include "Parser.hpp"
#include "Scene.hpp"

int main()
{
    std::unique_ptr<Scene> scene = nullptr;

    try
    {
        scene = std::make_unique<Scene>(SceneConfig{ Parser::ParseFile("scene1.test") });
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
