#include <iostream>

class Student
{
public:
    Student()
    {
        std::cout << "constructor called" << std::endl;
    }
};

int main()
{
    Student student;
}
