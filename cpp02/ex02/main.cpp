#include "Fixed.hpp"
#include <iomanip>

void test(std::string test, const Fixed a)
{
    std::cout << std::fixed;
    std::cout << test << " : " << a << std::endl;
}

int main( void ) {
    
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    
    std::cout << "<subject tests>" << std::endl;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl << std::endl; 

    std::cout << "<my tests>" << std::endl;
    test("--a", --a);
    test("a--", a--);
    test("a", a);

    Fixed small(5.2f);
    Fixed big(8.4f);
    Fixed zero(0);

    test("small", small);
    test("big", big);
    test("min(small, big)", Fixed::min(small, big));
    test("max(small, big)", Fixed::max(small, big));
    test("big > small", big > small);
    test("big >= small", big >= small);
    test("big > big", big > big);
    test("big >= big", big >= big);
    test("big < small", big < small);
    test("big <= small", big <= small);
    test("big < big", big < big);
    test("big <= big", big <= big);
    test("big == big", big == big);
    test("big == small", big == small);
    test("big != big", big != big);
    test("big != small", big != small);
    test("big + small", big + small);
    test("big - small", big - small);
    test("big * small", big * small);
    test("big / small", big / small);
    test("big / zero", big / zero);
    test("zero / big", zero / big);

	return 0;
}
