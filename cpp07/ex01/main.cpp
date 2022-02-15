#include "color.hpp"
#include "iter.hpp"

template< typename T>
void incrementValue(T& val) {
    val++;
}

template< typename T>
void printValue(const T& val) {
    std::cout << val << std::endl;
}

void testChar()
{
    std::cout << YELLOW << "testChar" << RESET << std::endl;
    char array[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    ::iter(array, 5, incrementValue);
    std::cout << array << "\n" << std::endl;
}

void testInt()
{
    std::cout << YELLOW << "testInt" << RESET << std::endl;
    int array[] = {1, 2, 3, 4, 5};
    ::iter(array, 5, incrementValue);
    for (size_t i = 0; i < 5; i++)
        std::cout << array[i] << std::endl;
    std::cout << std::endl;
}

void testFloat()
{
    std::cout << YELLOW << "testFloat" << RESET << std::endl;
    float array[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    ::iter(array, 5, incrementValue);
    for (size_t i = 0; i < 5; i++)
        std::cout << array[i] << std::endl;
    std::cout << std::endl;
}

void testString()
{
    std::cout << YELLOW << "testString" << RESET << std::endl;
    std::string a[] = {"hello", "world"};
    ::iter(a, 2, printValue);
    std::cout << std::endl;
}

int main()
{
    testChar();
    testInt();
    testFloat();
    testString();
}
