#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "color.hpp"

class Animal
{
    protected:
        std::string _type;

    public:
        Animal(std::string type = "Animal");
        virtual ~Animal();
        Animal(Animal const &other);
        Animal &operator=(Animal const &other);

        std::string getType() const;
        virtual void makeSound() const;
};

#endif
