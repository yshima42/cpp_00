#include <iostream>
#include <string>

#include "color.hpp"
#include "contact.hpp"
#include "phonebook.hpp"

Phonebook::Phonebook() : contact_head(0) {}

Phonebook::~Phonebook() {}

static std::string	readline(std::string prompt)
{
	std::string	input;

	while (true)
    {
		std::cout << prompt;
		std::getline(std::cin, input);
		if (std::cin.eof() || std::cin.bad())
        {
            std::cout << std::endl << RED << "Error: Phonebook is closed." << RESET << std::endl;
			exit(EXIT_FAILURE);
		}
		if (std::cin.fail())
        {
            std::cout << std::endl << RED << "Error: Invalid input, try again." << RESET << std::endl;
			continue ;
		}
		break ;
	}
	return (input);
}

void Phonebook::start()
{
    std::string line;

    std::cout << YELLOW << "<< Welcome to My Awesome Phonebook >>" << RESET << std::endl;
    std::cout << "Please enter a command. [ADD/SEARCH/EXIT]" << std::endl;
    while (true)
    {
        line = readline("Phonebook > ");
        if (line == "ADD")
            add();
        else if (line == "SEARCH")
            search();
        else if (line == "EXIT")
            break ;
        else
            std::cout << RED << "Error: Invalid command. Valid commands:[ADD/SEARCH/EXIT]" << RESET << std::endl;
    }
}

void Phonebook::add()
{
    if (contact_head == MAX_CONTACTS)
        contact_head = 0;
    page[contact_head].fill(contact_head);
    contact_head++;
}

static void printHeader()
{
    std::cout << std::endl;
    std::cout << "[Index]|First Name| Last Name| Nickname |" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
}

void Phonebook::show()
{
    printHeader();
    for (int i = 0; i < MAX_CONTACTS; i++)
    {
        std::cout << "[  " << i << "  ]";
        page[i].showName();
    }
    std::cout << std::endl;
}

static bool isBetween(int n, int min, int max)
{
    if (n >= min && n <= max)
        return (true);
    else
        return (false);
}

static bool isNumber(std::string str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!std::isdigit(str[i]))
            return (false);
    }
    return (true);
}

static int readIndex()
{
    std::string line;
    int index;

    while (true)
    {
        line = readline("Type index number: ");
        if (isNumber(line) && line.size() == 1)
        {
            index = line[0] - '0';
            if (isBetween(index, 0, MAX_CONTACTS - 1))
                return (index);
        }
        std::cout << RED << "Error: please type index number between 0-7" << RESET << std::endl;
    }
}

void	Phonebook::search()
{
    int index;

    show();
    index = readIndex();
    page[index].showAll(index);
    std::cout << std::endl;
}
