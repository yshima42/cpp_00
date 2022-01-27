#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog: Default Constructor" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog: Destructor" << std::endl;
}

Dog::Dog(Dog const &other)
{
    std::cout << "Dog: Copy Constructor" << std::endl;
    *this = other;
}

Dog &Dog::operator=(Dog const &other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    std::cout << "Dog: Assinataion Operator" << std::endl;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << GREEN << "Dog: <type:" + _type + "> " << "Wooooooooooffff(I'm Dog)" << RESET << std::endl;
}
