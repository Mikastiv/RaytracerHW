#include <iostream>

#include "Parser.hpp"

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

    system("pause");
}
