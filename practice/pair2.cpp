#include <iostream>
#include <utility>
#include <string>

int main()
{
    std::pair<int, const char*> a(10, "abc");
    std::pair<int, const char*> b;
    std::pair<int, std::string> c;

    b = a;
    c = b;

    std::cout << a.first << ", " << a.second << "\n"
              << b.first << ", " << b.second << "\n"
              << c.first << ", " << c.second << std::endl;
}
