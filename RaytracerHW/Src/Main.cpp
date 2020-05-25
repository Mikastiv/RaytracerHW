#include <iostream>

#include "Parser.hpp"

int main()
{
    try
    {
        std::vector<Config> c = Parser::ParseFile("scene1.test");
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
