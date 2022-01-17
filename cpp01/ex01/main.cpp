#include "Zombie.hpp"

int main()
{
    int N = 5;
    Zombie *zombies = zombieHorde(N, "hZombie");
    while (N--)
        zombies[N].announce();
    delete [] zombies;
}
