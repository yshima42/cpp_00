#ifndef INCLUDE_GUARD_ZOMBIE_HPP
#define INCLUDE_GUARD_ZOMBIE_HPP

#include <iostream>
#include <sys/wait.h>

class Zombie
{
    private:
        std::string _name;

    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie();
        void setName(std::string name);
        void announce( void );
};

Zombie* zombieHorde(int N, std::string name);

#endif

