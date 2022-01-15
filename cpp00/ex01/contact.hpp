#ifndef INCLUDE_GUARD_CONTACT_HPP
#define INCLUDE_GUARD_CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
    private:

        std::string first_name;
        std::string last_name;
        std::string nick_name;
        std::string phone_number;
        std::string darkest_secret;
        
        bool isFilled;

    public:

        Contact();
        ~Contact();

        void		setFirstName(const std::string str);
		void		setLastName(const std::string str);
		void		setNickName(const std::string str);
		void    	setPhoneNumber(const std::string str);
		void		setDarkestSecret(const std::string str);
        void        contactFill();

		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickName() const;
		std::string	getPhoneNumber() const;
		std::string	getDarkestSecret() const;

        int         checkContactFill() const;
};

#endif

