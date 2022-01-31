#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : _type("AMateria")
{
}

AMateria::AMateria(std::string const & type) : _type(type)
{
}

AMateria::~AMateria()
{
}

AMateria::AMateria(AMateria const &other)
{
    *this = other;
}

AMateria &AMateria::operator=(AMateria const &other)
{
    if (this != &other)
    {
        _type = other._type;
    }
    return *this;
}

std::string const & AMateria::getType() const
{
    return _type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << target.getName() << std::endl;
}

