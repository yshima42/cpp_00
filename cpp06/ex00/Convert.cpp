#include "Convert.hpp"

#include "color.hpp"

Convert::Convert(std::string const &str) : _str(str) {}
Convert::~Convert() {}

// getters for attributes
char Convert::get_c() const { return _c; }
int Convert::get_i() const { return _i; }
float Convert::get_f() const { return _f; }
double Convert::get_d() const { return _d; }

// getters for strings
const std::string Convert::get_c_str() const { return _c_str; }
const std::string Convert::get_i_str() const { return _i_str; }
const std::string Convert::get_f_str() const { return _f_str; }
const std::string Convert::get_d_str() const { return _d_str; }
const std::string Convert::get_str() const { return _str; }
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

bool Convert::isChar() {
  if ((_str.length() == 1 && !std::isdigit(_str[0])) ||
      (_str.length() == 3 && _str[0] == '\'' && _str[1] >= 0 &&
       _str[1] <= 127 && _str[2] == '\''))
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
  if (p == end || *end || errno == ERANGE || _str == "+nanf" || _str == "-nanf")
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
  if (p == end || *end || errno == ERANGE || _str == "+nan" || _str == "-nan")
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
  // use ostringstream for converting from different types to string
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
  oss << _f << ".0f";
  _f_str = oss.str();
  oss.str("");
  oss.clear();

  // set _d_str
  oss << _d << ".0";
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
  if (static_cast<long>(_f) <= INT_MIN || static_cast<long>(_f) >= INT_MAX)
    oss << "impossible";
  else
    oss << _i;
  _i_str = oss.str();
  oss.str("");
  oss.clear();

  // set _f_str
  if (_i == _f)
    oss << _i << ".0f";
  else
    oss << _f << "f";
  _f_str = oss.str();
  oss.str("");
  oss.clear();

  // set _d_str
  if (_i == _d)
    oss << _i << ".0";
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
  if (static_cast<long>(_d) <= INT_MIN || static_cast<long>(_d) >= INT_MAX)
    oss << "impossible";
  else
    oss << _i;
  _i_str = oss.str();
  oss.str("");
  oss.clear();

  // set _f_str
  if (_i == _f)
    oss << _i << ".0f";
  else
    oss << _f << "f";
  _f_str = oss.str();
  oss.str("");
  oss.clear();

  // set _d_str
  if (_i == _d)
    oss << _i << ".0";
  else
    oss << _d;
  _d_str = oss.str();
}

void Convert::setStrsError() {
  _c_str = "impossible";
  _i_str = "impossible";
  _f_str = "impossible";
  _d_str = "impossible";
}

std::ostream &operator<<(std::ostream &ost, const Convert &rhs) {
  // if you want to test the values in the class, use the following functions
  // ost << "_c: " << rhs.get_c() << "\n";
  // ost << "_i: " << rhs.get_i() << "\n";
  // ost << "_f: " << rhs.get_f() << "\n";
  // ost << "_d: " << rhs.get_d() << "\n";

  // output for the subject
  ost << "char: " << rhs.get_c_str() << "\n";
  ost << "int: " << rhs.get_i_str() << "\n";
  ost << "float: " << rhs.get_f_str() << "\n";
  ost << "double: " << rhs.get_d_str() << "\n";

  return ost;
}
