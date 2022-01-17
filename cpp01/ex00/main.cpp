#include "Zombie.hpp"

int main()
{
    Zombie *zombie = newZombie("nZombie");
    zombie->announce();
    delete zombie;
    randomChump("rZombie");
}
