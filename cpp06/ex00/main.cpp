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
  } catch (std::exception const &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
