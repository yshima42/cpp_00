#include "ScavTrap.hpp"
#include "FragTrap.hpp"
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
    {
        std::cout << std::endl;
        std::cout << GREEN << "< FragTrap test >" << RESET << std::endl;
        FragTrap fBob("fBob");
        fBob.attack("enemy");
        fBob.showStatus();
        std::cout << std::endl;
        fBob.takeDamege(70);
        fBob.showStatus();
        std::cout << std::endl;
        fBob.takeDamege(50);
        fBob.showStatus();
        std::cout << std::endl;
        fBob.beRepaired(30);
        fBob.showStatus();
        std::cout << std::endl;
        fBob.highFivesGuys(); 
        std::cout << std::endl;
    }
}
