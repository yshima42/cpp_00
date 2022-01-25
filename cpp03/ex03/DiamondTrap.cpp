#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("ClapName"), _name("DiamondName")
{
    _hitpoints = FragTrap::f_HP;
    _energyPoints = ScavTrap::s_EP;
    _attackDamage = FragTrap::f_AD;

    std::cout << "DiamondTrap Default Constructor called: " << _name << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name+"_clap_name"), _name(name)
{
    _hitpoints = FragTrap::f_HP;
    _energyPoints = ScavTrap::s_EP;
    _attackDamage = FragTrap::f_AD;

    std::cout << "DiamondTrap Constructor called: " << _name << std::endl;
}


DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Destructor called: " << _name << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &other)
{
    *this = other;
    std::cout << "DiamondTrap Copy Constructor called: " << _name << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other)
{
    if (this != &other)
    {
        _name = other._name;
        ClapTrap::_name = other.ClapTrap::_name;
		_hitpoints = other._hitpoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "DiamondTrap Assignation Operator Overload called: " << _name << std::endl;
    return *this;
}

void DiamondTrap::attack(std::string const & target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "Name    : " + _name  << std::endl
              << "ClapName: " + ClapTrap::_name  << std::endl;
}
