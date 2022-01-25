#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap()
{
    _hitpoints = f_HP;
    _energyPoints = f_EP;
    _attackDamage = f_AD;

    std::cout << "FragTrap Default Constructor called: " << _name << std::endl;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name)
{
    _hitpoints = f_HP;
    _energyPoints = f_EP;
    _attackDamage = f_AD;

    std::cout << "FragTrap Constructor called: " << _name << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called: " << _name << std::endl;
}

FragTrap::FragTrap(FragTrap const &other)
{
    std::cout << "FragTrap Copy Constructor called: " << _name << std::endl;
    *this = other;
}

FragTrap &FragTrap::operator=(FragTrap const &other)
{
    std::cout << "FragTrap Assignation Operator Overload called: " << _name << std::endl;
    if (this != &other)
    {
        _name = other._name;
        _hitpoints = other._hitpoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

void FragTrap::attack(const std::string &target)
{
    std::cout << "FragTrap " << _name << " attacks " << target << ", cousing "
        << _attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " request positive high five." << std::endl;

}
