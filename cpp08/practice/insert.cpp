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
  IntVector v(5, 3);  // 3を5こvectorに入れる

  IntVector::iterator it;

  it = v.insert(v.end() - 1, 0);
  PrintVector(v);

  v.insert(it, 3, 99);
  PrintVector(v);

  const int a[] = {10, 11, 12};
  v.insert(v.begin(), a, a + 3);
  PrintVector(v);
}
