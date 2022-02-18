#include <iostream>
#include <vector>

int main() {
  std::vector<int> v;
  v.reserve(1000);
  v.push_back(0);

  std::cout << v.capacity() << std::endl;

  std::vector<int>(v).swap(v);
  std::cout << v.capacity() << std::endl;
}
