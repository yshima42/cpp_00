#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    protected:
        std::string _name;
        unsigned int _hitpoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;

        static const unsigned int HP = 10;
        static const unsigned int EP = 10;
        static const unsigned int AD = 0;

    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const &other);
        ~ClapTrap();
        ClapTrap &operator=(ClapTrap const &other);

        void attack(std::string const &target);
        void takeDamege(unsigned int amount);
        void beRepaired(unsigned int amount);
        void showStatus() const;
};

#endif
