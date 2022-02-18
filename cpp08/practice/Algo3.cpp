#include <algorithm>
#include <iostream>
#include <vector>

#define numof(array) (sizeof(array) / sizeof *(array))

int main() {
  std::vector<int> data(5);

  std::fill(data.begin(), data.end(), 3);

  std::for_each(data.begin(), data.end(), [](int x) { std::cout << x << ","; });
}
