#include "Karen.hpp"
#include "color.hpp"

void test(std::string level)
{
    Karen a;
    std::cout << YELLOW << level << RESET << std::endl;
    a.complain(level);
    std::cout << std::endl;
}

int main()
{
    test("DEBUG");
    test("INFO");
    test("WARNING");
    test("ERROR");
    test("a");
    test("");
}
