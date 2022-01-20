#include "Karen.hpp"
#include "color.hpp"
#include <cstdlib>

enum e_level
{
    UNDEFINED,
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

int check_level(std::string level)
{ 
    int i_level = (level == "DEBUG") * DEBUG + (level == "INFO") * INFO +
                  (level == "WARNING") * WARNING + (level == "ERROR") * ERROR;
    return (i_level);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: ./karenFilter \"level\"" << std::endl;
        return(EXIT_FAILURE);
    }

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
