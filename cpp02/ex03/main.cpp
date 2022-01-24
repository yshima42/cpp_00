#include "Point.hpp"
#include "color.hpp"

void test(const Point a, const Point b, const Point c, const Point p)
{
    std::cout << std::fixed;
    std::cout << YELLOW << p << " in " << "a" << a << "b" << b << ",c" << c << RESET << std::endl;
    std::cout << "pab: " << Point::sign(p,a,b) << ", pbc: " << Point::sign(p,b,c) << ", pca: " << Point::sign(p,c,a) << std::endl;
    std::cout << (bsp(a, b, c, p) ? "true" : "false") << std::endl << std::endl;
}

int main()
{
    std::cout << CYAN << "< At vertex >" << RESET << std::endl;
    test(Point(0, 1), Point(0, 0), Point(1, 0), Point(0, 0));
    test(Point(1, 1), Point(0, 1), Point(1, 0), Point(0, 1));

    std::cout << CYAN << "< On edge >" << RESET << std::endl;
    test(Point(0, 0), Point(0, 1), Point(1, 0), Point(0.5, 0.5));

    std::cout << CYAN << "< Outside >" << RESET << std::endl;
    test(Point(0, 0), Point(0, 1), Point(1, 0), Point(1.2, 0.7));
	test(Point(0,-1), Point(1,1), Point(-1,1), Point(0, -2));


    std::cout << CYAN << "< Inside >" << RESET << std::endl;
    test(Point(0, 0), Point(0, 1), Point(1, 0), Point(0.4, 0.3));
	test(Point(0,-1), Point(1,1), Point(-1,1), Point(0, 0.959));

    {
        std::cout << CYAN << "< Copy Constructor >" << RESET << std::endl;
        Point	original(10.2, 14.5);
        Point	copy(original);
        std::cout << "original: " << original << std::endl;
        std::cout << "copy	: " << copy << std::endl << std::endl;
    }
    {
        std::cout << CYAN << "< Assignation Operator = >" << RESET << std::endl;
        Point	original(10.2, 14.5);
        Point	copy(15.1, 28.0);
        std::cout << "before copy	: " << copy << std::endl;
        std::cout << "before original	: " << original << std::endl;
        copy = original;
        std::cout << "after copy	: " << copy << std::endl << std::endl;
    }
}
