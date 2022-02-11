#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <cerrno>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

class Convert {
 public:
  enum valueType { UNDEFINE, CHAR, INT, FLOAT, DOUBLE };
  Convert(const std::string &str = "");
  virtual ~Convert();
  Convert(Convert const &other);
  Convert &operator=(Convert const &other);

  bool isChar();
  bool isInt();
  bool isFloat();
  bool isDouble();

  void setChar();

  const std::string getChar() const;

  void detectType();
  const std::string getType() const;
  void convertPrint(Convert &cv);

  static const std::string k_NonDisplayable;
  static const std::string k_Impossible;

 private:
  std::string _str;
  std::string _char;
  std::string _int;
  std::string _float;
  std::string _double;
  int _valueType;
};

std::ostream &operator<<(std::ostream &ost, const Convert &rhs);

#endif
