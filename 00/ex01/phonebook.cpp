#include <cstdlib>
#include <iostream>
#include <string>
#include <string_view>

#include "color.hpp"
#include "phonebook.hpp"

Phonebook::Phonebook() : p(0)
{
}

Phonebook::~Phonebook()
{
}

static std::string readline(std::string str)
{
    std::string input;

    while (true)
    {
        std::cout << str;
        std::getline(std::cin, input);
        if (std::cin.eof())
        {
            std::cout << std::endl << "Error" << std::endl;
            exit(EXIT_FAILURE);
        }
        if (std::cin.fail())
        {
            std::cout << std::endl << "Invalid string, try again." << std::endl;
            continue ;
        }
        break ;
    }
    return (input);
}

static void showUsage()
{
    std::cout << "Usage: ADD, SEARCH, EXIT commands are avalable" << std::endl;
}

void Phonebook::start()
{
    std::string line;

    while (true)
    {
        line = readline("Phonebook >");
        if (line == "ADD")
            add();
        else if (line == "SEARCH")
            search();
        else if (line == "EXIT")
            break ;
        else
         showUsage();
    }
}



void	PhoneBook::search()
{
	int order;

	if (NbAdd)
	{
		for (order = 1; order <= size; order++)
			display_oneline(order);
		std::string	order_input = get_input("order see more >", 10);
		order = order_input.at(0) - '0';
		if (order_input.size() == 1 &&  1 <= order && order <= size)
			display_detail(order);
		else
			std::cout << "invalid order" << std::endl;
	}
	else
		std::cout << RED << "phonebook is empty" << RESET << std::endl;
}

void	PhoneBook::start()
{
	try
	{
		while (true)
		{
			std::string input = get_input(">", 1);
			if (input == "EXIT")
				break ;
			else if (input == "ADD")
				add();
			else if (input == "SEARCH")
				search();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Error" << RESET << std::endl;
	}
}
