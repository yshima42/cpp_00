#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
        static const int    MATERIA_NUM = 4;

        std::string         _name;
        AMateria*           _materia[MATERIA_NUM]; 

    public:
        Character();
        Character(std::string const & name);
        virtual ~Character();
        Character(Character const &other);
        Character &operator=(Character const &other);

        virtual std::string const & getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
};

#endif
