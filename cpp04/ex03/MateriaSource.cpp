#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < MATERIA_NUM; i++)
        _materia[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < MATERIA_NUM; i++)
    {
        if (_materia[i])
            delete _materia[i];
    }
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
    for (int i = 0; i < MATERIA_NUM; i++)
    {
        _materia[i] = NULL;
    }
    *this = other;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
    if (this != &other)
    {
        for (int i = 0; i < MATERIA_NUM; i++)
        {
            delete _materia[i];
            if (other._materia[i])
                _materia[i] = other._materia[i]->clone();
            else
                _materia[i] = NULL;
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* NewMateria)
{
    if (!NewMateria)
    {
        std::cout << "Error: Invalid Materia" << std::endl;
        return ;
    }
    for (int i = 0; i < MATERIA_NUM; i++)
    {
        if (!_materia[i])
        {
            _materia[i] = NewMateria;
            std::cout << "Learn: " << _materia[i]->getType() << std::endl;
            return ;
        }
    }
    std::cout << "Materias are full" << std::endl;

}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < MATERIA_NUM; i++)
    {
        if (_materia[i] && _materia[i]->getType() == type)
        {
            std::cout << "Create: " << _materia[i]->getType() << std::endl;
            return _materia[i]->clone();
        }
    }
    std::cout << "Error: Couldn't create materia" << std::endl;
    return NULL;
}
