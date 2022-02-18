#include "MutantStack.hpp"

MutantStack::MutantStack()
{
}

MutantStack::~MutantStack()
{
}

MutantStack::MutantStack(MutantStack const &other)
{
    *this = other;
}

MutantStack &MutantStack::operator=(MutantStack const &other)
{
    if (this != &other)
    {
    }
    return *this;
}
