#include <iostream>
#include <string>

template <typename T>
void write(T a);

int main()
{
    write<int>(100);
    write<double>(3.5);
    write<char>('x');
    write<std::string>("xyz");
}

template <typename T>
void write(T a)
{
    std::cout << a << std::endl;
}
