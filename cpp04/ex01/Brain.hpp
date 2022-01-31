#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
    private:
        static const int MAX_IDEAS = 100;

        std::string _ideas[MAX_IDEAS];

    public:
        Brain();
        //Brain(const std::string idea);
        virtual ~Brain();
        Brain(Brain const &other);
        Brain &operator=(Brain const &other);

        void showIdeas() const;
        void setIdea(unsigned int i, const std::string idea);
};

#endif
