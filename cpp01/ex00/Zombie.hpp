#ifndef INCLUDE_GUARD_ZOMBIE_HPP
#define INCLUDE_GUARD_ZOMBIE_HPP

#include <iostream>
#include <sys/wait.h>

class Zombie
{
    private:
        std::string _name;

    public:
        Zombie(std::string name = "bob");
        ~Zombie();
        void announce( void );
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif

