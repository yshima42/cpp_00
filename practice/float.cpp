#include <iostream>

int main()
{
    float a = 12.4;
    int b = 12;

    a = a * (1 << 8);
    b = b * (1 << 8);

    
    std::cout << a << std::endl;
    std::cout << b << std::endl;


}
