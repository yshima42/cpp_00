#include <iostream>
#include <vector>

typedef std::vector<int> IntVector;

void PrintVector(const IntVector& v) {
  const IntVector::size_type size = v.size();
  for (IntVector::size_type i = 0; i < size; ++i) {
    std::cout << v[i] << "\n";
  }
  std::cout << std::endl;
}

int main() {
  IntVector v;

  v.assign(5, 3);
  PrintVector(v);

  const int a[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
  v.assign(a, a + 10);
  PrintVector(v);
}
