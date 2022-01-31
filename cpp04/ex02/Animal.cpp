#include "Animal.hpp"

Animal::Animal(std::string type) : _type(type)
{
    std::cout << "Animal: Constructor" << _type << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal: Destructor" << std::endl;
}

Animal::Animal(Animal const &other)
{
    std::cout << "Animal: Copy Constructor" << std::endl;
    *this = other;
}

Animal &Animal::operator=(Animal const &other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    std::cout << "Animal: Assinataion Operator" << std::endl;
    return *this;
}

//void Animal::makeSound() const
//{
//    std::cout << GREEN << "Animal: <type:" + _type + "> " << "Hi, I'm Animal." << RESET << std::endl;
//}

std::string Animal::getType() const
{
    return _type;
}
