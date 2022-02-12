#include <cstdlib>
#include <iostream>

#include "Convert.hpp"

void showUsage() { std::cout << "Usage: ./convert <value>\n"; }

int main(int ac, char *av[]) {
  if (ac != 2) {
    showUsage();
    return 0;
  }
  try {
    Convert cv(av[1]);
    cv.detectType();
    cv.setValues();
    cv.setStrs();
    std::cout << cv;
  } catch (std::exception const &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}

// void detect_leak(void) __attribute__((destructor));

// void detect_leak(void) { system("leaks -q convert"); }
