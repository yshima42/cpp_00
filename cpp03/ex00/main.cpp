#include "ClapTrap.hpp"

int main()
{
    ClapTrap bob("Bob");

    bob.attack("Ken");
    bob.showStatus();
    std::cout << std::endl;
    bob.takeDamege(7);
    bob.showStatus();
    std::cout << std::endl;
    bob.takeDamege(5);
    bob.showStatus();
    std::cout << std::endl;
    bob.beRepaired(3);
    bob.showStatus();
}
