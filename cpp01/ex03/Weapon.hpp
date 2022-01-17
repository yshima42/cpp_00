#ifndef INCLUDE_GUARD_WEAPON_HPP
#define INCLUDE_GUARD_WEAPON_HPP

#include <iostream>

class Weapon
{
    private:
        std::string _type;

    public:
        Weapon(std::string type);
        ~Weapon();

        void setType(std::string type);
        const std::string& getType();
};

#endif

