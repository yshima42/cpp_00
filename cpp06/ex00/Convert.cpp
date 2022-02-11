#include "Convert.hpp"
#include "color.hpp"

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

void Convert::setValues() {
  switch (_valueType) {
    case CHAR:
      setValuesFromChar();
      break;
    case INT:
      setValuesFromInt();
      break;
    case FLOAT:
      setValuesFromFloat();
      break;
    case DOUBLE:
      setValuesFromDouble();
      break;
  }
}

void Convert::setValuesFromChar() {
  // set char type value
  if (_str.length() == 1) {
    _c = _str[0];
  } else if (_str.length() == 3) {
    _c = _str[1];
  }

  // set other type values
  _i = static_cast<int>(_c);
  _f = static_cast<float>(_c);
  _d = static_cast<double>(_c);
}

void Convert::setValuesFromInt() {
  // set int type value
  _i = std::atoi(_str.c_str());

  // set other type value
  _c = static_cast<char>(_i);
  _f = static_cast<float>(_i);
  _d = static_cast<double>(_i);
}

void Convert::setValuesFromFloat() {
  // set float type value
  char *end;
  _f = std::strtof(_str.c_str(), &end);

  // set other type value
  _c = static_cast<char>(_f);
  _i = static_cast<int>(_f);
  _d = static_cast<double>(_f);
}

void Convert::setValuesFromDouble() {
  // set double type value
  char *end;
  _d = std::strtod(_str.c_str(), &end);

  // set other type value
  _c = static_cast<char>(_d);
  _i = static_cast<int>(_d);
  _f = static_cast<float>(_d);
}

void Convert::setStrs() {
  switch (_valueType) {
    case CHAR:
      setStrsFromChar();
      break;
    case INT:
      setStrsFromInt();
      break;
    case FLOAT:
      setStrsFromFloat();
      break;
    case DOUBLE:
      setStrsFromDouble();
      break;
    default:
      setStrsError();
  }
}

void Convert::setStrsFromChar() {
//use ostringstream for converting from different types to string
  std::ostringstream oss;

  // set _c_str
  oss << '\'' << _c << '\'';
  _c_str = oss.str();
  oss.str("");
  oss.clear();

  // set _i_str
  oss << _i;
  _i_str = oss.str();
  oss.str("");
  oss.clear();

  // set _f_str
  oss << _f << ".0f";
  _f_str = oss.str();
  oss.str("");
  oss.clear();

  // set _d_str
  oss << _d << ".0";
  _d_str = oss.str();
}

void Convert::setStrsFromInt() { 
    std::ostringstream oss; 

    // set _c_str
    if ((_i >= 0 && _i <= 31) || _i == 127)
        oss << "Non desplayable";
    else if (_i >= 32 && _i <= 126)
        oss << '\'' << _c << '\'';
    else
        oss << "impossible";
    _c_str = oss.str();
    oss.str("");
    oss.clear();

    // set _i_str
    oss << _i;
    _i_str = oss.str();
    oss.str("");
    oss.clear();

    // set _f_str
    oss << _i << ".0f";
    _f_str = oss.str();
    oss.str("");
    oss.clear();

    // set _d_str
    oss << _i << ".0";
    _d_str = oss.str();
}

void Convert::setStrsFromFloat() {
    std::ostringstream oss; 

    // set _c_str
    if ((_i >= 0 && _i <= 31) || _i == 127)
        oss << "Non desplayable";
    else if (_i >= 32 && _i <= 126)
        oss << '\'' << _c << '\'';
    else
        oss << "impossible";
    _c_str = oss.str();
    oss.str("");
    oss.clear();

    // set _i_str
    oss << _i;
    _i_str = oss.str();
    oss.str("");
    oss.clear();

    // set _f_str
    if (_i == _f)
        oss << _f << ".0f";
    else
        oss << _f << "f";
    _f_str = oss.str();
    oss.str("");
    oss.clear();

    // set _d_str
    if (_i == _d)
        oss << _d << ".0";
    else
        oss << _d;
    _d_str = oss.str();
}

void Convert::setStrsFromDouble() {
    std::ostringstream oss; 

    // set _c_str
    if ((_i >= 0 && _i <= 31) || _i == 127)
        oss << "Non desplayable";
    else if (_i >= 32 && _i <= 126)
        oss << '\'' << _c << '\'';
    else
        oss << "impossible";
    _c_str = oss.str();
    oss.str("");
    oss.clear();

    // set _i_str
    oss << _i;
    _i_str = oss.str();
    oss.str("");
    oss.clear();

    // set _f_str
    if (_i == _d)
        oss << _d << ".0f";
    else
        oss << _d << "f";
    _f_str = oss.str();
    oss.str("");
    oss.clear();

    // set _d_str
    if (_i == _d)
        oss << _d << ".0";
    else
        oss << _d;
    _d_str = oss.str();

}

void Convert::setStrsError() {
    // set _c_str

    // set _i_str
    // set _f_str
    // set _d_str

}

// void Convert::setChar() {
//   switch (_valueType) {
//     case CHAR:
//       if (_str.length() == 3 && _str[0] == '\'' && !std::isprint(_str[1])) {
//         _c_str = k_NonDisplayable;
//       } else {
//         _c_str = k_Impossible;
//       }
//   }
// }

// void Convert::setInt() {
//   const char *p = _str.c_str();
//   char *end;
//   errno = 0;
//   long x = std::strtol(p, &end, 10);
//   std::ostringstream oss;
//
//   if (_str.length() == 1 && !std::isdigit(_str[0])) {
//     oss << static_cast<int>(_str[0]);
//     _i_str = oss.str();
//   } else if (_str.length() == 3 && _str[0] == '\'' && std::isprint(_str[1])
//   &&
//              _str[2] == '\'') {
//     oss << static_cast<int>(_str[1]);
//     _i_str = oss.str();
//   } else if (p == end || *end || errno == ERANGE || x < INT_MIN ||
//              x > INT_MAX) {
//     _i_str = k_Impossible;
//   } else {
//     oss << x;
//     _i_str = oss.str();
//   }
// }

char Convert::get_c() const { return _c; }
int Convert::get_i() const { return _i; }
float Convert::get_f() const { return _f; }
double Convert::get_d() const { return _d; }

const std::string Convert::get_c_str() const { return _c_str; }
const std::string Convert::get_i_str() const { return _i_str; }
const std::string Convert::get_f_str() const { return _f_str; }
const std::string Convert::get_d_str() const { return _d_str; }
const std::string Convert::get_str() const { return _str; }

Convert::Convert(std::string const &str) : _str(str) {}

Convert::~Convert() {}

Convert::Convert(Convert const &other) { *this = other; }

Convert &Convert::operator=(Convert const &other) {
  if (this != &other) {
    // this->_char = other._char;
    // this->_int = other._int;
    // this->_float = other._float;
    // this->_double = other._double;
    // this->_str = other._str;
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
std::ostream &operator<<(std::ostream &ost, const Convert &rhs) {
    //ost << YELLOW << "_str: " << rhs.get_str() << "\n" << RESET;
  ost << "_c: " << rhs.get_c() << "\n";
  ost << "_i: " << rhs.get_i() << "\n";
  ost << "_f: " << rhs.get_f() << "\n";
  ost << "_d: " << rhs.get_d() << "\n";
  ost << "char: " << rhs.get_c_str() << "\n";
  ost << "int: " << rhs.get_i_str() << "\n";
  ost << "float: " << rhs.get_f_str() << "\n";
  ost << "double: " << rhs.get_d_str() << "\n";

  return ost;
}
