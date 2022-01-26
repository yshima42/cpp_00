#include "ScavTrap.hpp"
#include "color.hpp"

int main()
{
    {
        std::cout << GREEN << "< ClapTrap test >" << RESET << std::endl;
        ClapTrap cBob("cBob");

        cBob.attack("enemy");
        cBob.showStatus();
        std::cout << std::endl;
        cBob.takeDamege(7);
        cBob.showStatus();
        std::cout << std::endl;
        cBob.takeDamege(5);
        cBob.showStatus();
        std::cout << std::endl;
        cBob.beRepaired(3);
        cBob.showStatus(); 
        std::cout << std::endl;
    }
    {
        std::cout << std::endl;
        std::cout << GREEN << "< ScavTrap test >" << RESET << std::endl;
        ScavTrap sBob("sBob");

        sBob.attack("enemy");
        sBob.showStatus();
        std::cout << std::endl;
        sBob.takeDamege(70);
        sBob.showStatus();
        std::cout << std::endl;
        sBob.takeDamege(50);
        sBob.showStatus();
        std::cout << std::endl;
        sBob.beRepaired(30);
        sBob.showStatus();
        std::cout << std::endl;
        sBob.guardGate(); 
        std::cout << std::endl;
    }
}
