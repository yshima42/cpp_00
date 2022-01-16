#include "Phonebook.hpp"
#include "color.hpp"
#include <string>

Phonebook::Phonebook() : index_head(0) {}

Phonebook::~Phonebook() {}

static std::string readline(std::string prompt, int width)
{
    std::string input;

    while (true)
    {
        std::cout << CYAN << std::setw(width) << prompt << RESET;
        std::getline(std::cin, input);
        if (std::cin.eof() || std::cin.fail() || std::cin.bad())
            throw std::exception();
        break;
    }
    return (input);
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
        line = readline("Type index number: ", 16);
        if (isNumber(line) && line.size() == 1)
        {
            index = line[0] - '0';
            if (isBetween(index, 0, MAX_CONTACTS - 1))
                return (index);
        }
        std::cout << RED << "Error: please type index number between 0-7" << RESET << std::endl;
    }
}

void Phonebook::add()
{
    std::string phone_number;

    if (index_head == MAX_CONTACTS) 
       index_head = 0;
   contacts[index_head].setFirstName(readline("First name: ", SUB_WIDTH));
   contacts[index_head].setLastName(readline("Last name: ", SUB_WIDTH));
   contacts[index_head].setNickName(readline("Nickname: ", SUB_WIDTH));
   while (true)
   {
        phone_number = readline("Phone Number: ", SUB_WIDTH);
        if (isNumber(phone_number)) 
            break ;
        else
            std::cout << RED << "  Error: Please input digits for the phone number" << RESET << std::endl;;
   }
   contacts[index_head].setPhoneNumber(phone_number);
   contacts[index_head].setDarkestSecret(readline("Darkest Secret: ", SUB_WIDTH));
   contacts[index_head].contactFill();
   std::cout << GREEN << "Contact is saved in index No:" << index_head << RESET << std::endl;
   index_head++;
}

static std::string to_10chrs(std::string content)
{
	if (content.size() > 10)
		return (content.replace(9, 1, ".").substr(0, 10));
    return (content);
}

void Phonebook::showNames(int index)
{
    std::cout << std::setw(HEADER_WIDTH) << to_10chrs(contacts[index].getFirstName()) << "|" ;
    std::cout << std::setw(HEADER_WIDTH) << to_10chrs(contacts[index].getLastName()) << "|" ;
    std::cout << std::setw(HEADER_WIDTH) << to_10chrs(contacts[index].getNickName()) << "|" << std::endl;
}

static void printHeader()
{
    std::cout << std::endl;
    std::cout << "[Index]|First Name| Last Name| Nickname |" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
}

void Phonebook::showIndex()
{
    printHeader();
    for (int i = 0; i < MAX_CONTACTS; i++)
    {
        std::cout << "[  " << i << "  ]|";
        showNames(i);
    }
    std::cout << std::endl;
}

void Phonebook::showAll(int index)
{
    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickName() << std::endl;
    std::cout << "Phone number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}

void	Phonebook::search()
{
    int index;

    showIndex();
    index = readIndex();
    if (contacts[index].checkContactFill())
        showAll(index);
    else
        std::cout << RED << "Index [" << index << "] is not registered." << RESET << std::endl;
    std::cout << std::endl;
}

void Phonebook::start()
{
    std::cout << YELLOW << "<< Welcome to My Awesome Phonebook >>" << RESET << std::endl;
    std::cout << CYAN << "Please enter a command. [ADD/SEARCH/EXIT]" << RESET << std::endl;
    try
    {
        while (true)
        {
            std::string line = readline("Phonebook > ", 11); 
            if (line == "ADD")
                add();
            else if (line == "SEARCH")
                search();
            else if (line == "EXIT")
                break;
            else
                std::cout << RED << "Error: Invalid command.\nPlease type a valid command[ADD/SEARCH/EXIT]" << RESET << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Error" << RESET << std::endl;
    }
}
