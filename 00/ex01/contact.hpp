#ifndef INCLUDE_GUARD_UUID_369C785C_D3CF_47B8_A8E8_E791C7AF6EDC
#define INCLUDE_GUARD_UUID_369C785C_D3CF_47B8_A8E8_E791C7AF6EDC

#include <iostream>

class Contact
{
	private:
        bool		_isFilled;
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
	public:
		Contact();
        ~Contact();
        std::string getField(int i);
        void setField(int i, std::string info);
        void showName();
        void showAll();
        bool isEmpty();
        void fill();
};

#endif

