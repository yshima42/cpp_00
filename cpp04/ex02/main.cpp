#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void outOfMem()
{
    std::cerr << "Error: Out of Memory" << std::endl;
    std::abort();
}

void testBrain()
{
    std::cout << "---testBrain---" << std::endl;
    {
        Brain brain1;
        brain1.showIdeas();
    }
    {
        Brain brain2;

        brain2.setIdea(1, "like fish");
        brain2.setIdea(99, "hello");
        brain2.setIdea(101, "omg");
        brain2.showIdeas();
    }
}

void testDogBrain()
{
    std::cout << "---testDogBrain---" << std::endl;
    //{
    //    Dog dog;
    //    dog.showIdeas();
    //}
    //{
    //    Dog dog;
    //    Dog copyDog(dog);

    //    dog.showIdeas();
    //}
    {
        Dog *dog_ptr = new Dog();
        dog_ptr->setIdea(2, "sample");
        Dog copyDog(*dog_ptr);

        std::cout << "dog_ptr adress: " << dog_ptr << std::endl;
        std::cout << "copyDog address: " << &copyDog << std::endl;

        dog_ptr->showIdeas();
        delete dog_ptr;
        copyDog.showIdeas();
    }
    std::cout << std::endl;
}

void testCatBrain()
{
    std::cout << "---testCatBrain---" << std::endl;
    //{
    //    Cat cat;
    //    cat.showIdeas();
    //}
    {
        Cat *cat_ptr = new Cat();
        cat_ptr->setIdea(2, "sample");
        Cat copyCat(*cat_ptr);

        std::cout << "cat_ptr adress: " << cat_ptr << std::endl;
        std::cout << "copyCat address: " << &copyCat << std::endl;

        cat_ptr->showIdeas();
        delete cat_ptr;
        copyCat.showIdeas();
    }
    std::cout << std::endl;
}

void testSubject()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    //following statment occurs error
    //const Animal* k = new Animal("Animal");

    j->makeSound();
    i->makeSound();
    
    delete j;//should not create a leak
    delete i; 
}

int main()
{
    std::set_new_handler(outOfMem);
    testSubject();
    //testBrain();
    //testDogBrain();
    //testCatBrain();

    std::cout << std::endl;
    system("leaks -q a.out");

}

