#include "Replace.hpp"

Replace::Replace(std::string const &s1, std::string const &s2, std::istream &cin, std::ostream &cout) :
        _s1(s1), _s2(s2), _cin(cin), _cout(cout)
{
    if (_s1.empty() || _s2.empty())
        throw "s1 or s2 cannot be empty";
}

Replace::~Replace() {}

void Replace::replace()
{
    for (std::string line; std::getline(_cin, line);) 
    {
        std::size_t len_s1 = _s1.size();
        std::size_t len_s2 = _s2.size();
        std::size_t c_pos = line.find(_s1, 0);
        while (c_pos != std::string::npos)
        {
            line.erase(c_pos, len_s1);
            line.insert(c_pos, _s2);
            c_pos += len_s2;
            c_pos = line.find(_s1, c_pos);
        }
        _cout << line;
        if (!_cin.eof())
            _cout << std::endl;
    }
}
