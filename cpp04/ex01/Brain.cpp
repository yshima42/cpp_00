#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain: Default Constructor" << std::endl;
}

//Brain::Brain(const std::string idea)
//{
//    std::cout << "Brain: Constructor" << std::endl;
//}

Brain::~Brain()
{
    std::cout << "Brain: Destructor" << std::endl;
}

Brain::Brain(Brain const &other)
{
    std::cout << "Brain: Copy Constructor" << std::endl;
    *this = other;
}

Brain &Brain::operator=(Brain const &other)
{
    if (this != &other)
    {
        for (int i = 0; i < MAX_IDEAS; i++)
            _ideas[i] = other._ideas[i];
    }
    std::cout << "Brain: Assinataion Operator" << std::endl;
    return *this;
}

void Brain::setIdea(unsigned int i, const std::string idea)
{
    if (i >= MAX_IDEAS)
    {
        std::cerr << "Error: Invalid Index" << std::endl;
        return ;
    }
    
    _ideas[i] = idea;
}

void Brain::showIdeas() const
{
    for (int i = 0; i < MAX_IDEAS; i++)
    {
        std::cout << "[" << i << "]" << _ideas[i] << std::endl;
    }
}
