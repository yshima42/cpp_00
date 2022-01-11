#ifndef INCLUDE_GUARD_UUID_02269914_05B5_4128_BC97_415EF2011529
#define INCLUDE_GUARD_UUID_02269914_05B5_4128_BC97_415EF2011529

#include "contact.hpp"

const int MAX_CONTACTS = 8;


class Phonebook
{
	private:
        Contact index[MAX_CONTACTS];
        int contact_header;
	public:
        Phonebook();
        ~Phonebook();
        void start();
        void show();
        void search();
};

#endif

