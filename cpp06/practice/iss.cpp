#include <sstream>
#include <iostream>

int main()
{
    std::string str = "42";
    std::istringstream iss(str);

    int num;
    iss >> num;
    std::cout << num << std::endl;
}
