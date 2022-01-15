#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::ifstream ifs("hello.txt");
    if (!ifs)
    {
        std::cerr << "oh"<< std::endl;
        std::exit(1);
    }

    std::string buf;
    ifs >> buf;
    std::cout << buf << std::endl;

}
