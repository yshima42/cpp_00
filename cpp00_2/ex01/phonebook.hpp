#ifndef INCLUDE_GUARD_PHONEBOOK_HPP
#define INCLUDE_GUARD_PHONEBOOK_HPP

#include "contact.hpp"

const int MAX_CONTACTS = 8;

class Phonebook
{
	private:
        Contact page[MAX_CONTACTS];
        int contact_head;
	public:
        Phonebook();
        ~Phonebook();
        void start();
        void add();
        void show();
        void search();
};

#endif

