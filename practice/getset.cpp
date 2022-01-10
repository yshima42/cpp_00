#include <iostream>

class Student
{
private:
    int id_;
public:
    int get_id()
    {
        return this->id_;
    }
    void set_id(int id)
    {
        if (id < 0)
        {
            std::cout << "Invalid id: " << id << std::endl;
            return;
        }
        this->id_ = id;
    }
};

int main()
{
    Student student;

    student.set_id(-1);
    student.set_id(42);

    std::cout << "student id: " << student.get_id() << std::endl;
}