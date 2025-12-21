#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
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
    std::cout << "--------------more-tests-------------\n";
    {
        MateriaSource src;
        src.learnMateria(new Ice());
        src.learnMateria(new Cure());
        Character hero("Hero");
        AMateria* AM[] =  { src.createMateria("ice"),
                            src.createMateria("ice"),
                            src.createMateria("ice"),
                            src.createMateria("cure") };
        for (int i = 0; i < 4; i++)
            hero.equip(AM[i]);
        Character enemy("Enemy");
        for (int i = 0; i < 4; i++)
            hero.use(i, enemy);
    }
    return 0;
}
