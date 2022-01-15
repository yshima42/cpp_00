#include <iostream>


class MyClass {
public:
    MyClass();
    ~MyClass();

    static int GetObjectCount();

private:
    static int msObjectCount;  // static????????
};
int MyClass::msObjectCount = 0;

MyClass::MyClass()
{
    ++msObjectCount;
}

MyClass::~MyClass()
{
    --msObjectCount;
}

int MyClass::GetObjectCount()
{
    return msObjectCount;
}

int main()
{
    std::cout << MyClass::GetObjectCount() << std::endl;

    MyClass c1;
    MyClass* c2 = new MyClass(); 
    std::cout << MyClass::GetObjectCount() << std::endl;

    delete c2;
    std::cout << MyClass::GetObjectCount() << std::endl;


}
