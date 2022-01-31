#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
    private:

    public:
        Cure();
        virtual ~Cure();
        Cure(Cure const &other);
        Cure &operator=(Cure const &other);

        virtual AMateria* clone() const;
        void use(ICharacter & target);
};

#endif

