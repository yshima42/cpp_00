#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  std::vector<int> v(10);
  try {
    v.at(3) = 10;
    int a = v.at(3);
    std::cout << a << std::endl;

    v.at(50) = 10;
    std::cout << "hello" << std::endl;
  } catch (const std::out_of_range& e) {
    std::cout << e.what() << "ooooo" << std::endl;
  }
}
