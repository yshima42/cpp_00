#include <iostream>
#include <stack>

using namespace std;

int main()
{
    cout << "stack" << endl;
    int thedata[] = {45, 34, 56, 27, 71, 50, 62};
    stack<int> s;
    cout << "stack size: " << s.size() << endl;

    int i;
    cout << "pusing 4 elements " << endl;
    for (i = 0; i < 4; ++i)
        s.push(thedata[i]);
    cout << "the stack size: " << s.size() << endl;
    cout << "popping 3 elements " << endl;
    for (i = 0; i < 3; ++i)
    {
        cout << s.top() << endl;
        s.pop();
    }

    cout << "stack size: " << s.size() << endl;
    cout << "pushing 3 elements " << endl;
    for (i = 4; i < 7; ++i) {
        s.push(thedata[i]);
    }
    cout << "the stack size: " << s.size() << endl;
    cout << "poppint all elements" << endl;
    while (!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
    cout << "the stack size: " << s.size() << endl;
}
