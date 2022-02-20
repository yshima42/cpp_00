#include <iostream>
#include <list>

int main()
{
    typedef std::list<int> IntList;

    const int table[] = {0, 1, 2, 3, 4};
    IntList lst(table, table + 5);

    IntList::const_iterator itEnd = lst.end();
    for (IntList::const_iterator it = lst.begin(); it != itEnd; it++)
    {
        std::cout << *it << "\n";
    }
}
