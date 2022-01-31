#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

class ICharacter;

class AMateria
{
    protected:
        std::string _type;

    public:
        AMateria();
        AMateria(std::string const & type);
        virtual ~AMateria();
        AMateria(AMateria const &other);
        AMateria &operator=(AMateria const &other);

        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif
