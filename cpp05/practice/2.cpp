#include <iostream>

int main()
{
    try
    {
        throw "errorrrrrrr!";
    }
    catch (const char* fError)
    {
        std::cout << fError << std::endl;
    }
}
