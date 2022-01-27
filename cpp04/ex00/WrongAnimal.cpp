#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
    std::cout << "WrongAnimal: Constructor" << _type << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal: Destructor" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other)
{
    std::cout << "WrongAnimal: Copy Constructor" << std::endl;
    *this = other;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    std::cout << "WrongAnimal: Assinataion Operator" << std::endl;
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << GREEN << "WrongAnimal: <type:" + _type + "> " << "Hi, I'm WrongAnimal." << RESET << std::endl;
}

std::string WrongAnimal::getType() const
{
    return _type;
}

