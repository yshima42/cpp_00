#include "Zombie.hpp"

void outOfMem()
{
    std::cerr << "Error: Out of memory" << std::endl;
    std::abort();
}

int main()
{
    std::set_new_handler(outOfMem); 
    int N = 5;
    Zombie *zombies = zombieHorde(N, "hZombie");
    while (N--)
        zombies[N].announce();
    delete [] zombies;
}
