#include <iostream>

template< typename T>
T const & max( T const & x, T const & y ) {
    return ( x>=y ? x : y );
}

int main()
{
    int a = 1;
    int b = 2;
    std::cout << max(a, b) << std::endl;
}

