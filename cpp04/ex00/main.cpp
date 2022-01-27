#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"


void Test_Without_Pointer()
{
    std::cout << YELLOW << "< Without Using Pointer >" << RESET << std::endl;
    std::cout << CYAN << "< Normal_Animals >" << RESET << std::endl;
    {
        Animal a("_Animal");
        a.makeSound();
        Dog d;
        d.makeSound();
        Cat c;
        c.makeSound();
    }
    std::cout << CYAN << "< Wrong_Animals >" << RESET << std::endl;
    {
        WrongAnimal a("_WrongAnimal");
        a.makeSound();
        Cat c;
        c.makeSound();
    }
}

void Test_With_Pointer()
{
    std::cout << YELLOW << "< With Using Pointer >" << RESET << std::endl;
    std::cout << CYAN << "< Normal_Animals >" << RESET << std::endl;
    {
        Animal* a = new Animal("_Animal");
        a->makeSound();
        Animal* d = new Dog();
        d->makeSound();
        Animal* c = new Cat();
        c->makeSound();
    }
    std::cout << CYAN << "< Wrong_Animals >" << RESET << std::endl;
    {
        WrongAnimal* a = new WrongAnimal("_WrongAnimal");
        a->makeSound();
        WrongAnimal* c = new WrongCat();
        c->makeSound();
    }
}

int main()
{
    Test_Without_Pointer();
    std::cout << std::endl;
    Test_With_Pointer();
    std::cout << std::endl;
}
