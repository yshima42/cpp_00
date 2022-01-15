#include <iostream>
#include <string>
#include <sstream>

int main()
{
    std::ostringstream oss;
    oss << "hello" << 123;

    std::string str(oss.str());

    std::cout << str << std::endl;
}
