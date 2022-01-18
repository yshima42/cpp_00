#include "Karen.hpp"
#include "color.hpp"

enum e_level
{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    UNDEFINED
};

int check_level(std::string level)
{
    if (level == "DEBUG")
        return (DEBUG);
    else if (level == "INFO")
        return (INFO);
    else if (level == "WARNING")
        return (WARNING);
    else if (level == "ERROR")
        return (ERROR);
    else
        return (UNDEFINED);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        std::cout << "Usage: ./karenFilter \"level\"" << std::endl;

    Karen karen;
    std::string level = argv[1];

    switch (check_level(level))
    {
        case DEBUG:
            std::cout << "[ DEBUG ]" << std::endl;
            karen.complain("DEBUG");
            std::cout << std::endl;
        case INFO:
            std::cout << "[ INFO ]" << std::endl;
            karen.complain("INFO");
            std::cout << std::endl;
        case WARNING:
            std::cout << "[ WARNING ]" << std::endl;
            karen.complain("WARNING");
            std::cout << std::endl;
        case ERROR:
            std::cout << "[ ERROR ]" << std::endl;
            karen.complain("ERROR");
            std::cout << std::endl;
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            std::cout << std::endl;
            break;
    }

} 
