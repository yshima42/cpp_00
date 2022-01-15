#include <cstdlib>
#include <fstream>
#include <iostream>

int main()
{
    std::ofstream ofs("hello.txt");
    if (!ofs)
    {
        std::cerr << "fail" << std::endl;
        std::exit(1);
    }
    ofs << "Helllllloooo world" << std::endl;
}
