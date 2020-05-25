#include <iostream>

#include "Parser.hpp"
#include "Image.hpp"

int main()
{
    std::vector<Config> c{};

    try
    {
        c = Parser::ParseFile("scene1.test");
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

    Image img(256, 256);
    img.Clear({ 0, 255, 255 });
    img.Save("test.png");
}
