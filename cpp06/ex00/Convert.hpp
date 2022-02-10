#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <cerrno>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

class Convert {
 private:
  std::string _str;
  char _c;
  int _i;
  float _f;
  double _d;

 public:
  Convert(const std::string &str = "");
  virtual ~Convert();
  Convert(Convert const &other);
  Convert &operator=(Convert const &other);

  bool isChar();
  bool isInt();
  bool isFloat();
  bool isDouble();
};

#endif
