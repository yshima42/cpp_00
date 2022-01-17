#include "iostream"

int main()
{
    std::string str = "HI THIS IS BRAIN";

    std::string* stringPTR = &str; 
    std::string& stringREF = str;
    
    std::cout << "stringPTR Address: " << stringPTR << std::endl;
    std::cout << "stringREF Address: " << &stringREF << std::endl;

    std::cout << "stringPTR: " << *stringPTR << std::endl;
    std::cout << "stringREF: " << stringREF << std::endl;

}
