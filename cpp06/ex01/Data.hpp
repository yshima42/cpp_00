#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data {
 public:
  Data(const std::string &str_data = "yshimazu", const int &int_data = 10);
  virtual ~Data();

  // getter
  const std::string &getStr() const;
  const int &getInt() const;

 private:
  Data(Data const &other);
  Data &operator=(Data const &other);

  std::string _str_data;
  int _int_data;
};

std::ostream &operator<<(std::ostream &ost, const Data &rhs);
uintptr_t serialize(Data *ptr);
Data *deserialize(uintptr_t raw);

#endif
