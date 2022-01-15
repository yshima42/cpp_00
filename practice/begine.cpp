#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

void print(int x)
{
    std::cout << x << " ";
}

int main()
{
    {
        std::vector<int> v = {1,2,3};

        decltype(v)::iterator first = std::begin(v);
        decltype(v)::iterator last = std::end(v);

        std::for_each(first, last, print);

    }
    std::cout << std::endl;
    
}
