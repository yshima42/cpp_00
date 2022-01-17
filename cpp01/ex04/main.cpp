#include "Replace.hpp"
#include "color.hpp"

int main(int argc, char *argv[])
{
    try 
    {
        if (argc != 4 || !argv[1][0] || !argv[2][0] || !argv[3][0])
            throw "Usage: ./replace file_name s1 s2";
        std::string infile(argv[1]);
        std::ifstream ifs(infile);
        std::ofstream ofs(infile + ".replace", std::ios::out | std::ios::trunc);
        if (ifs.fail() || ofs.fail())
            throw "Failed to open file";
        Replace file(argv[2], argv[3], ifs, ofs);
        file.replace();
    }
    catch (char const *err_msg)
    {
        std::cerr << RED << err_msg << RESET << std::endl;
    }
}
