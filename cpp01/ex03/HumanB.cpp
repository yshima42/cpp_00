#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB() {}

void HumanB::attack()
{
    std::cout << _name << " attacks with his ";
    if (_weapon)
        std::cout << _weapon->getType();
    else
        std::cout << "fists";
    std::cout << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
    _weapon = &weapon;
}
