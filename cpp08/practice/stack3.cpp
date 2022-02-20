#include <iostream>
#include <stack>

typedef std::stack<int> IntStack;

int main()
{
    IntStack iStack, iStack2;
    for (int i = 0; i < 5; ++i)
    {iStack.push(i);
    }

    iStack2 = iStack;


    std::cout << iStack.size() << iStack2.size() << std::endl;

}
