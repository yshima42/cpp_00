#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    private:
        static const unsigned int f_HP = 100;
        static const unsigned int f_EP = 100;
        static const unsigned int f_AD = 30;

    public:
        FragTrap();
        FragTrap(std::string const &name);
        ~FragTrap();
        FragTrap(FragTrap const &other);
        FragTrap &operator=(FragTrap const &other);

        void attack(std::string const &target);
        void highFivesGuys(void);
};

#endif
