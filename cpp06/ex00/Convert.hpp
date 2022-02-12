#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <cerrno>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

class Convert {
 public:
  enum valueType { UNDEFINE, CHAR, INT, FLOAT, DOUBLE };
  Convert(const std::string &str = "");
  virtual ~Convert();

  void detectType();
  bool isChar();
  bool isInt();
  bool isFloat();
  bool isDouble();

  // set different types of valiables
  void setValues();
  void setValuesFromChar();
  void setValuesFromInt();
  void setValuesFromFloat();
  void setValuesFromDouble();

  // set *_str valiables
  void setStrs();
  void setStrsFromChar();
  void setStrsFromInt();
  void setStrsFromFloat();
  void setStrsFromDouble();
  void setStrsError();

  // getters
  char get_c() const;
  int get_i() const;
  float get_f() const;
  double get_d() const;

  const std::string get_c_str() const;
  const std::string get_i_str() const;
  const std::string get_f_str() const;
  const std::string get_d_str() const;
  const std::string get_str() const;

  const std::string getType() const;
  void convertPrint(Convert &cv);

 private:
  const std::string _str;
  int _valueType;

  char _c;
  int _i;
  float _f;
  double _d;

  std::string _c_str;
  std::string _i_str;
  std::string _f_str;
  std::string _d_str;

  // did not use the following functions
  Convert(Convert const &other);
  Convert &operator=(Convert const &other);
};

std::ostream &operator<<(std::ostream &ost, const Convert &rhs);

#endif
