#include <iostream>

int main()
{
    std::string input;

    while (true)
    {
        std::getline(std::cin, input);
        std::cout << input << std::endl;
        if (std::cin.eof() || std::cin.bad()) {
			std::cout << std::endl << "Error" << std::endl;
			exit(EXIT_FAILURE);
		}
		if (std::cin.fail()) {
			std::cout << std::endl << "Invalid string, try again." << std::endl;
			continue ;
		}
    }
}
