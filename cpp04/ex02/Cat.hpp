#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain* _brain;

    public:
        Cat();
        virtual ~Cat();
        Cat(Cat const &other);
        Cat &operator=(Cat const &other);

        virtual void makeSound() const;
        void showIdeas() const;
        void setIdea(unsigned int i, const std::string idea);
};

#endif
