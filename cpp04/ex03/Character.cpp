#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : _name("default")
{
    for (int i = 0; i < MATERIA_NUM; i++)
        _materia[i] = NULL;
}

Character::Character(std::string const & name) : _name(name)
{
    for (int i = 0; i < MATERIA_NUM; i++)
        _materia[i] = NULL;
}

Character::~Character()
{
    for (int i = 0; i < MATERIA_NUM; i++)
    {
        if (_materia[i])
            delete _materia[i];
    }
}

Character::Character(Character const &other)
{
    for (int i = 0; i < MATERIA_NUM; i++) 
    {
		_materia[i] = NULL;
	}
    *this = other;
}

Character &Character::operator=(Character const &other)
{
    if (this != &other)
    {
        _name = other._name;
        for (int i = 0; i < MATERIA_NUM; i++)
        {
            delete _materia[i];
            if (other._materia[i])
                _materia[i] = other._materia[i]->clone();
            else
                _materia[i] = NULL;
        }
    }
    return *this;
}

std::string const & Character::getName() const
{
    return _name;
}

void Character::equip(AMateria* NewMateria)
{
    if (!NewMateria)
    {
        std::cout << "Error: Materia cannot be NULL" << std::endl;
        return ;
    }
    for (int i = 0; i < MATERIA_NUM; i++)
    {
        if (!_materia[i])
        {
            _materia[i] = NewMateria;
            std::cout << "Equip: " << _materia[i]->getType() << std::endl;
            return ;
        }
    }
    std::cout << _name << "'s materias are full" << std::endl;
}

void Character::unequip(int idx)
{
    if (idx < MATERIA_NUM)
        _materia[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < MATERIA_NUM && _materia[idx])
        _materia[idx]->use(target);
    else
        std::cout << "slot ["<< idx << "] is empty" << std::endl;
}
