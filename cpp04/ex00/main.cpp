#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"


void Test_Without_Pointer()
{
    std::cout << YELLOW << "< Without Using Pointer >" << RESET << std::endl;
    std::cout << CYAN << "< Correct_Animals >" << RESET << std::endl;
    {
        Animal a("Animal");
        Dog d;
        Cat c;
        a.makeSound();
        d.makeSound();
        c.makeSound();
    }
    std::cout << CYAN << "< Wrong_Animals >" << RESET << std::endl;
    {
        WrongAnimal a("WrongAnimal");
        Cat c;
        a.makeSound();
        c.makeSound();
    }
}

void Test_With_Pointer()
{
    std::cout << YELLOW << "< With Using Pointer >" << RESET << std::endl;
    std::cout << CYAN << "< Correct_Animals >" << RESET << std::endl;
    {
        const Animal* meta = new Animal();
        const Animal* i = new Dog();
        const Animal* j = new Cat();

        std::cout << meta->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        std::cout << j->getType() << " " << std::endl;
        meta->makeSound();
        i->makeSound();
        j->makeSound();

        delete meta;
        delete i;
        delete j;

        std::cout	<<	std::endl;
    }
    std::cout << CYAN << "< Wrong_Animals >" << RESET << std::endl;
    {
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* j = new WrongCat();

        std::cout << meta->getType() << " " << std::endl;
        std::cout << j->getType() << " " << std::endl;
        meta->makeSound();
        j->makeSound();

        delete meta;
        delete j;

        std::cout	<<	std::endl;
    }
}

int main()
{
    Test_Without_Pointer();
    std::cout << std::endl;
    Test_With_Pointer();
    std::cout << std::endl;
}
