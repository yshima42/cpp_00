#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
    private:

    public:
        Ice();
        virtual ~Ice();
        Ice(Ice const &other);
        Ice &operator=(Ice const &other);

        virtual AMateria* clone() const;
        virtual void use(ICharacter & target);
};

#endif

