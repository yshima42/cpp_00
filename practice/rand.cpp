#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(NULL));
    std::cout << rand() << std::endl;
    std::cout << rand() << std::endl;
    std::cout << rand() << std::endl;
}