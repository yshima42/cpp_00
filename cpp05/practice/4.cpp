#include <iostream>

void Func()
{
    try {
    throw 1;
    } catch (int nError) {
    throw "Error"; 
    }
    catch (const char *str)
    {
        std::cout << str << std::endl;
    }
}

int main()
{
    try {
    Func();
    } catch (const char *str) {
        std::cout << "main: " << str << std::endl; 
    }
}
