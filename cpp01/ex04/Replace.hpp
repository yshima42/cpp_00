#ifndef INCLUDE_GUARD_REPLACE_HPP
#define INCLUDE_GUARD_REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>

class Replace
{
    private:
        std::string _s1;
        std::string _s2;
        std::istream &_cin;
        std::ostream &_cout;
    
    public:
        Replace(std::string const &s1, std::string const &s2, std::istream &cin, std::ostream &cout);
        ~Replace();

        void replace();
};

#endif

