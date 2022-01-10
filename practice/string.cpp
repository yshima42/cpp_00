#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        std::string str(argv[i]);
        std::cout << str << std::endl;
    }
}