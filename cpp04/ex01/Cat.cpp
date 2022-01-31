#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat: Default Constructor" << std::endl;

    _brain = new Brain();
    if (!_brain)
        exit(EXIT_FAILURE);
}

Cat::~Cat()
{
    std::cout << "Cat: Destructor" << std::endl;

    delete _brain;
}

Cat::Cat(Cat const &other) 
{
    std::cout << "Cat: Copy Constructor" << std::endl;

    _brain = new Brain();
    *this = other;
}

Cat &Cat::operator=(Cat const &other)
{  
    if (this != &other)
    {
        this->_type = other._type;
        *this->_brain = *other._brain;
    }
    std::cout << "Cat: Assinataion Operator" << std::endl;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << GREEN << "Cat: <type:" + _type + "> " << "Meeoooooooowwwwww(I'm Cat)" << RESET << std::endl;
}

void Cat::showIdeas() const
{
    _brain->showIdeas();
}

void Cat::setIdea(unsigned int i, const std::string idea)
{
    _brain->setIdea(i, idea);
}
