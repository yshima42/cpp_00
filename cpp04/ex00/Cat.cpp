#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat: Default Constructor" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat: Destructor" << std::endl;
}

Cat::Cat(Cat const &other)
{
    std::cout << "Cat: Copy Constructor" << std::endl;
    *this = other;
}

Cat &Cat::operator=(Cat const &other)
{  
    if (this != &other)
    {
        this->_type = other._type;
    }
    std::cout << "Cat: Assinataion Operator" << std::endl;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << GREEN << "Cat: <type:" + _type + "> " << "Meeoooooooowwwwww(I'm Cat)" << RESET << std::endl;
}

