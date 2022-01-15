#ifndef INCLUDE_GUARD_CONTACT_HPP
#define INCLUDE_GUARD_CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

const int NAME_WIDTH = 10;
const int FIELD_WIDTH = 15;

enum Field
{
    FIRST_NAME,
    LAST_NAME,
    NICK_NAME,
    PHONE_NBR,
    DARKEST_SECRET,
    FIELD_NUM
};

class Contact
{
	private:
        static const std::string field_name[FIELD_NUM];
        std::string field[FIELD_NUM];
        bool		_isFilled;

	public:
		Contact();
        ~Contact();
        std::string getField(enum Field field_num);
        void setField(enum Field field_num, std::string info);
        void showName();
        void showAll(int index);
        bool isEmpty();
        void fill(int contact_head);
};

#endif

