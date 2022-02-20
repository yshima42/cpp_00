#include <iostream>
#include <stack>

typedef std::stack<int> IntStack;

int main()
{
    IntStack iStack;

    for (int i = 0; i < 5; ++i){
        iStack.push(i);
    }

    std::cout << iStack.size() << "\n" << std::boolalpha << iStack.empty() << std::endl;
}
