#include <nl_types.h>

#include <iostream>

#include "Convert.hpp"
#include "color.hpp"

void testBoolFuncs(const std::string str) {
  Convert a(str);
  std::cout << "Char: " << (a.isChar() ? "True" : "False") << std::endl;
  std::cout << "Int: " << (a.isInt() ? "True" : "False") << std::endl;
  std::cout << "Float: " << (a.isFloat() ? "True" : "False") << std::endl;
  std::cout << "Double: " << (a.isDouble() ? "True" : "False") << std::endl;
}

void showType(const std::string str) {
  int idx = 0;
  Convert a(str);
  idx = a.isChar() + a.isInt() * 2 + a.isFloat() * 4 + a.isDouble() * 8;

  switch (idx) {
    case 0:
      std::cout << "Non of them: " << str << std::endl;
      break;
    case 1:
      std::cout << YELLOW << "Char: " << str << RESET << std::endl;
      break;
    case 2:
      std::cout << BLUE << "Int: " << str << RESET << std::endl;
      break;
    case 4:
      std::cout << GREEN << "Float: " << str << RESET << std::endl;
      break;
    case 8:
      std::cout << MAGENTA << "Double: " << str << RESET << std::endl;
      break;
    default:
      std::cout << RED << "Error" << RESET << std::endl;
      testBoolFuncs(str);
      break;
  }
}

void testOperator(const std::string str) {
  Convert a(str);
  a.detectType();
  a.setValues();
  a.setStrs();
  std::cout << a << std::endl;
}

void showUsage() { std::cout << "Usage: ./convert <value>\n"; }

int main(int ac, char *av[]) {
  if (ac != 2) {
    showUsage();
    return 0;
  }
  try {
    showType(av[1]);
    testOperator(av[1]);

  } catch (std::exception const &e) {
    std::cout << e.what() << std::endl;
  }
}
