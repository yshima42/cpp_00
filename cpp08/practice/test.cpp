#include <algorithm>
#include <iostream>

#define numof(array) (sizeof(array) / sizeof *(array))

int main() {
  int data[] = {1, 2, 3, 4};
  std::cout << *std::min_element(data, data + numof(data)) << std::endl;
}
