#include <iostream>

int main()
{
    int num;
    
    std::cin >> num;
    if (std::cin.eof())
    {
        std::exit(1);
    }
}