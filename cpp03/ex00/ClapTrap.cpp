#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("No name"), _hitpoints(HP), _energyPoints(EP), _attackDamage(AD) 
{
    std::cout << "ClapTrap Default Constructor called: " << _name << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitpoints(HP), _energyPoints(EP), _attackDamage(AD) 
{
    std::cout << "ClapTrap Constructor called: " << _name << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called: " << _name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other)
{
    std::cout << "ClapTrap Copy Constructor called: " << _name << std::endl;
    *this = other;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
    std::cout << "ClapTrap Assignation Operator Overload called: " << _name << std::endl;
    if (this != &other)
    {
        _name = other._name;
        _hitpoints = other._hitpoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

void ClapTrap::attack(std::string const & target)
{
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
        << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamege(unsigned int amount)
{
    if (amount < _hitpoints)
        _hitpoints -= amount;
    else
        _hitpoints = 0;

    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount)
{
    _hitpoints += amount;

    std::cout << "ClapTrap " << _name << " recovers " << amount << " points!" << std::endl;
}

void ClapTrap::showStatus() const
{
    std::cout << "Name  : " << _name << std::endl
              << "HP    : " << _hitpoints << std::endl
              << "EP    : " << _energyPoints << std::endl
              << "Damage: " << _attackDamage << std::endl; 
}
