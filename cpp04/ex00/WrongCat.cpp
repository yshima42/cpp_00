#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat: Default Constructor" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat: Destructor" << std::endl;
}

WrongCat::WrongCat(WrongCat const &other)
{
    std::cout << "WrongCat: Copy Constructor" << std::endl;
    *this = other;
}

WrongCat &WrongCat::operator=(WrongCat const &other)
{  
    if (this != &other)
    {
        this->_type = other._type;
    }
    std::cout << "WrongCat: Assinataion Operator" << std::endl;
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << GREEN << "WrongCat: <type:" + _type + "> " << "Meeoooooooowwwwww(I'm WrongCat)" << RESET << std::endl;
}

