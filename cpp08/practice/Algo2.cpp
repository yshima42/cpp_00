#include <iostream>

#define numof(array) (sizeof(array) / sizeof *(array))

template <typename T>
T min_element(T pB, T pE) {
  T pMin;
  for (T p = pMin = pB; p != pE; ++p)
    if (*p < *pMin) pMin = p;
  return pMin;
}

int main() {
  int data[] = {1, 2, 3, 4, 5};
  std::cout << *min_element(data, data + numof(data)) << std::endl;
}
