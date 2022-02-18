#include <iostream>
#include <vector>

int main() {
  std::vector<int> v;

  for (int i = 0; i < 5; ++i) {
    v.push_back(i);
  }

  std::cout << v.max_size() << "\n"
            << v.size() << "\n"
            << v.capacity() << std::endl;
  for (int i = 0; i < 5; i++) std::cout << v[i] << std::endl;
}
