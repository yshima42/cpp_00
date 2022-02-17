#include <exception>
#include <list>
#include <vector>

#include "color.hpp"
#include "easyfind.hpp"

typedef std::vector<int> IntVector;

void PrintVector(const IntVector& v) {
  const IntVector::size_type size = v.size();
  std::cout << "v = {";
  for (IntVector::size_type i = 0; i < size - 1; ++i) {
    std::cout << v[i] << ", ";
  }
  std::cout << v[v.size() - 1];
  std::cout << "}" << std::endl;
}

void testVector(int val) {
  std::vector<int> v(10);
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    v[i] = i * 3;
  }
  PrintVector(v);
  try {
    std::cout << "easyfind(v, " << val << "): ";
    std::vector<int>::const_iterator it = easyfind(v, val);
    std::cout << *it << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}

typedef std::list<int> IntList;

void PrintList(const IntList& lst) {
  const IntList::const_iterator itEnd = lst.end();
  std::cout << "l = ";
  for (IntList::const_iterator it = lst.begin(); it != itEnd; ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

void testList(int val) {
  std::list<int> l;
  l.push_back(10);
  l.push_back(13);
  l.push_back(3);
  l.push_back(5);
  l.push_back(8);
  PrintList(l);
  try {
    std::cout << "easyfind(l, " << val << "): ";
    std::list<int>::const_iterator it = easyfind(l, val);
    std::cout << *it << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}

int main() {
  std::cout << YELLOW << "---testVector---" << RESET << std::endl;
  testVector(3);
  std::cout << std::endl;
  testVector(4);
  std::cout << std::endl;
  testVector(9);
  std::cout << std::endl;

  std::cout << YELLOW << "---testList---" << RESET << std::endl;
  testList(3);
  std::cout << std::endl;
  testList(4);
  std::cout << std::endl;
  testList(10);
  std::cout << std::endl;
}
