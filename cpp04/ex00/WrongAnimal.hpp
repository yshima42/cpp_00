#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include "color.hpp"

class WrongAnimal
{
    protected:
        std::string _type;

    public:
        WrongAnimal(std::string name = "WrongAnimal");
        virtual ~WrongAnimal();
        WrongAnimal(WrongAnimal const &other);
        WrongAnimal &operator=(WrongAnimal const &other);

        std::string getType() const;
        void makeSound() const; 
};

#endif
