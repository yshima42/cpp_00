#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    _hitpoints = s_HP;
    _energyPoints = s_EP;
    _attackDamage = s_AD;

    std::cout << "ScavTrap Default Constructor called: " << _name << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _hitpoints = s_HP;
    _energyPoints = s_EP;
    _attackDamage = s_AD;

    std::cout << "ScavTrap Constructor called: " << _name << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called: " << _name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &other)
{
    std::cout << "ScavTrap Copy Constructor called: " << _name << std::endl;
    *this = other;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other)
{
    std::cout << "ScavTrap Assignation Operator Overload called: " << _name << std::endl;
    if (this != &other)
    {
        _name = other._name;
        _hitpoints = other._hitpoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

void ScavTrap::attack(std::string const &target)
{
    std::cout << "ScavTrap " << _name << " attacks " << target << ", cousing "
        << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " has entered in Gate Keeper mode." << std::endl; 
}
