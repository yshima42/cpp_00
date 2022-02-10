#include "Convert.hpp"

#include <stdexcept>

bool Convert::isChar() {
  if ((_str.length() == 1 && !std::isdigit(_str[0])) ||
      (_str.length() == 3 && _str[0] == '\'' && std::isprint(_str[1]) &&
       _str[2] == '\''))
    return true;
  else
    return false;
}

bool Convert::isInt() {
  const char *p = _str.c_str();
  char *end;
  errno = 0;
  long x = std::strtol(p, &end, 10);
  if (p == end || *end || errno == ERANGE || x < INT_MIN || x > INT_MAX)
    return false;
  else
    return true;
}

bool Convert::isFloat() {
  if (this->isDouble()) return false;
  if (_str[_str.length() - 1] != 'f')
    return false;
  std::string no_f_str = _str.substr(0, _str.length() - 1);
  const char *p = no_f_str.c_str();
  char *end;
  errno = 0;
  std::strtof(p, &end);
  if (p == end || *end || errno == ERANGE)
    return false;
  else
    return true;
}

bool Convert::isDouble() {
  if (this->isInt()) return false;
  const char *p = _str.c_str();
  char *end;
  errno = 0;
  std::strtod(p, &end);
  if (p == end || *end || errno == ERANGE)
    return false;
  else
    return true;
}

Convert::Convert(std::string const &str)
    : _str(str), _c(0), _i(0), _f(0), _d(0) {
}

Convert::~Convert() {}

Convert::Convert(Convert const &other) { *this = other; }

Convert &Convert::operator=(Convert const &other) {
  if (this != &other) {
    this->_c = other._c;
    this->_i = other._i;
    this->_f = other._f;
    this->_d = other._d;
    this->_str = other._str;
  }
  return *this;
}

// const std::string &Convert::getCtoStr() const {
//
//     return _c;
// }
//
// const std::string &Convert::getItoStr() const {return _i;}
// const std::string &Convert::getFtoStr() const {return _f;}
// const std::string &Convert::getDtoStr() const {return _d;}
//
// std::ostream &operator<<(std::ostream &ost, Convert const &rhs)
//{
//     ost <<
// }
