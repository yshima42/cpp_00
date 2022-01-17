#ifndef INCLUDE_GUARD_HUMANA_HPP
#define INCLUDE_GUARD_HUMANA_HPP
#include "Weapon.hpp"

class HumanA
{
    private:
        std::string _name;
        Weapon& _weapon;

    public:
        HumanA(std::string _name, Weapon& weapon);
        ~HumanA();
        void attack();
};
#endif

