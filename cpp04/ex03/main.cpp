#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

void outOfMem()
{
    std::cerr << "Error: Out of memory" << std::endl;
    std::abort();
}

void testIce()
{
    std::cout << "---testIce---" << std::endl;
    {
        Ice ice;
        Ice iceCopy(ice);
        Ice iceCopy2;

        iceCopy = ice;

        std::cout << ice.getType() << std::endl;
        std::cout << iceCopy.getType() << std::endl;
        std::cout << iceCopy2.getType() << std::endl;

        Character sample_cha("sample_cha");

        ice.use(sample_cha);
        iceCopy.use(sample_cha);
        iceCopy2.use(sample_cha);

        AMateria* ptr = ice.clone();

        Ice *iptr = static_cast<Ice*>(ptr);

        std::cout << ice.getType() << std::endl;
        std::cout << iptr->getType() << std::endl;

        iptr->use(sample_cha);
        static_cast<Ice*>(ptr)->use(sample_cha);
        delete ptr;
    }
}

void testCharacter()
{
    std::cout << "---testCharacter---" << std::endl;
    {
        Character char_A("char_A");
        Ice *ice = new Ice;
        Cure *cure = new Cure;

        char_A.equip(ice);
        char_A.equip(cure);
        Character char_Copy(char_A);
        Character char_Copy2;
        char_Copy2 = char_A;

        std::cout << char_A.getName() << std::endl;
        std::cout << char_Copy.getName() << std::endl;
        std::cout << char_Copy2.getName() << std::endl;

        Character enemy("Enemy");
        char_A.use(0, enemy);
        char_Copy.use(1, enemy);
        char_Copy2.use(2, enemy);
        char_Copy2.use(3, enemy);

    }
}


void testSubject()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");
    
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
}

int main()
{
    std::set_new_handler(outOfMem);
    testSubject();
    //testIce();
    //testCharacter();
    //system("leaks a.out");
}
