#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

class MutantStack
{
    public:
        MutantStack();
        virtual ~MutantStack();
        MutantStack(MutantStack const &other);
        MutantStack &operator=(MutantStack const &other);

    private:
};

#endif
