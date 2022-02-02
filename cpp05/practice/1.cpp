#include <exception>
#include <iostream>

void func(int n)
{
    switch(n)
    {
        case 0:
            throw std::range_error("range_error");
        case 1:
            throw std::overflow_error("overflow");
        case 2:
            throw std::underflow_error("underflow");
    }
}

int main()
{
    try{
        func(3);
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
}
