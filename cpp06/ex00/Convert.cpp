#include "Convert.hpp"

#include <stdexcept>

const std::string Convert::k_NonDisplayable = "Non displayable";
const std::string Convert::k_Impossible = "impossible";

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
  if (_str[_str.length() - 1] != 'f') return false;
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

void Convert::detectType() {
  if (this->isChar())
    _valueType = CHAR;
  else if (this->isInt())
    _valueType = INT;
  else if (this->isFloat())
    _valueType = FLOAT;
  else if (this->isDouble())
    _valueType = DOUBLE;
  else
    _valueType = UNDEFINE;
}

void Convert::setChar() {
  if (this->isChar()) {
    if (_str.length() == 1 && !std::isdigit(_str[0]))
      _char = "\'" + _str + "\'";
    else if (_str.length() == 3 && _str[0] == '\'' && std::isprint(_str[1]) &&
             _str[2] == '\'')
      _char = _str;
  } else {
    if (_str.length() == 3 && _str[0] == '\'' && !std::isprint(_str[1]))
      _char = k_NonDisplayable;
    else
      _char = k_Impossible;
  }
}

const std::string Convert::getChar() const { return _char; }

Convert::Convert(std::string const &str) : _str(str) {}

Convert::~Convert() {}

Convert::Convert(Convert const &other) { *this = other; }

Convert &Convert::operator=(Convert const &other) {
  if (this != &other) {
    this->_char = other._char;
    this->_int = other._int;
    this->_float = other._float;
    this->_double = other._double;
    this->_str = other._str;
  }
  return *this;
}

const std::string Convert::getType() const {
  switch (_valueType) {
    case CHAR:
      return "Char";
      break;
    case INT:
      return "Int";
      break;
    case FLOAT:
      return "Float";
      break;
    case DOUBLE:
      return "Double";
      break;
    default:
      return "Undefine";
      break;
  }
}

// void Convert::convertPrint(Convert &cv)
//{
//     cv.detectType();
//     switch (cv._valueType)
//     {
//
//     }
// }

// const std::string &Convert::getCtoStr() const {
//
//     return _c;
// }
//
// const std::string &Convert::getItoStr() const {return _i;}
// const std::string &Convert::getFtoStr() const {return _f;}
// const std::string &Convert::getDtoStr() const {return _d;}
//
std::ostream &operator<<(std::ostream &ost, const Convert &rhs)
{
    ost << "char: " << rhs.getChar() << "\n";

    return ost;
}
