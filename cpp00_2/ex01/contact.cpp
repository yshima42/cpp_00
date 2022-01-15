#include "contact.hpp"
#include "color.hpp"
#include <cstdlib>

const std::string Contact::field_name[FIELD_NUM] =
{
    "First Name",
    "Last Name",
    "Nickname",
    "Phone Number",
    "Darkest Secret"
};

Contact::Contact() : _isFilled(false) {}

Contact::~Contact() {}

std::string Contact::getField(enum Field field_num)
{
    return (field[field_num]);
}

void Contact::setField(enum Field field_num, std::string info)
{
    field[field_num] = info;
}

void Contact::showName()
{
    std::string output;

    for (int i = 0; i <= NICK_NAME; i++)
    {
        if (field[i].size() > NAME_WIDTH)
            output = field[i].substr(0, NAME_WIDTH - 1) + '.';
        else
            output = field[i];
        std::cout << '|' << std::right << std::setw(NAME_WIDTH) << output;
    }
    std::cout << '|' << std::endl;
}

/* static bool isNumber(std::string str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!std::isdigit(str[i]))
            return (false);
    }
    return (true);
} */

static std::string readline(std::string prompt)
{
    std::string input;

    while (true)
    {
        std::cout << std::left << std::setw(FIELD_WIDTH) << prompt << ": ";
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

void Contact::showAll(int index)
{
    if (!_isFilled)
        std::cout << RED << "Index [" << index << "] is not registered." << RESET << std::endl;
    else
    {
        std::cout << std::endl;
        for (int i = 0; i < FIELD_NUM; i++)
        {
            std::cout << std::left << std::setw(FIELD_WIDTH) << field_name[i];
            std::cout << ": " << field[i] << std::endl;       
        }       
    }
}

void Contact::fill(int contact_head)
{
    for (int i = 0; i < FIELD_NUM; i++)
        field[i] = readline(field_name[i]);
    _isFilled = true;
    std::cout << GREEN << "Contact is saved in index No:" << contact_head << RESET << std::endl;
}

