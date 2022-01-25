#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    private:
        static const unsigned int s_HP = 100;
        static const unsigned int s_EP = 50;
        static const unsigned int s_AD = 20;

    public:
        ScavTrap();
        ScavTrap(std::string name);
        ~ScavTrap();
        ScavTrap(ScavTrap const &other);
        ScavTrap &operator=(ScavTrap const &other);

        void attack(std::string const &target);
        void guardGate();
};

#endif
