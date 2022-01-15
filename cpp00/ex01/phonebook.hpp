#ifndef INCLUDE_GUARD_PHONEBOOK_HPP
#define INCLUDE_GUARD_PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>

const int MAX_CONTACTS = 8;
const int SUB_WIDTH = 16;
const int HEADER_WIDTH = 10;

class Phonebook
{
    private:
        Contact contacts[8];
        int index_head;
    public:
        Phonebook();
        ~Phonebook();
        void start();
        void add();
        void search();
        void showIndex();
        void showAll(int index);
        void showNames(int index);
};

#endif

