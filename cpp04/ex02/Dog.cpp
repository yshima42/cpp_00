#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog: Default Constructor" << std::endl;

    _brain = new Brain();
    if(!_brain)
        exit(EXIT_FAILURE);
}

Dog::~Dog()
{
    std::cout << "Dog: Destructor" << std::endl;

    delete _brain;
}

Dog::Dog(Dog const &other)
{
    std::cout << "Dog: Copy Constructor" << std::endl;

    _brain = new Brain();
    *this = other;
}

Dog &Dog::operator=(Dog const &other)
{
    if (this != &other)
    {
        this->_type = other._type;
        *this->_brain = *other._brain;
    }
    std::cout << "Dog: Assinataion Operator" << std::endl;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << GREEN << "Dog: <type:" + _type + "> " << "Wooooooooooffff(I'm Dog)" << RESET << std::endl;
}

void Dog::showIdeas() const
{
    _brain->showIdeas();
}

void Dog::setIdea(unsigned int i, const std::string idea)
{
    _brain->setIdea(i, idea);
}
