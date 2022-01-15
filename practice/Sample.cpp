#include <cstddef>
#include <iostream>

class Sample {

    public:
        int foo;

        Sample();
        ~Sample();

        void bar() const;
};

Sample::Sample() : foo(0)
{
    std::cout << "constructor called" << std::endl;
    return ;
}

Sample::~Sample() {
    std::cout << "destructor called" << std::endl;
    return; 
}

void Sample::bar() const 
{
    std::cout << "member function bar called" << std::endl;
    return ;
}

int main()
{
    Sample instance;
    Sample * instancep = &instance;

    int Sample::*p = NULL; //initialize
    void (Sample::*f)() const;

    p = &Sample::foo; //assign foo to p

    std::cout << "value of member foo: " << instance.foo << std::endl;
    instance.*p = 21;
    std::cout << "value of member foo: " << instance.foo << std::endl;
    instancep->*p = 42;
    std::cout << "value of member foo: " << instance.foo << std::endl;
    
    f = &Sample::bar;

    (instance.*f)();
    (instancep->*f)();

    return 0;

}
