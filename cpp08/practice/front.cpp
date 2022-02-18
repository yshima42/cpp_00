#include <iostream>
#include <vector>

int main() {
  std::vector<int> v(10);
  const std::vector<int>::size_type size = v.size();
  for (int i = 0; i < static_cast<int>(size); ++i) v[i] = i;

  std::cout << v.front() << std::endl;
  std::cout << v.back() << std::endl;
}
