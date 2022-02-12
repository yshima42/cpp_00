#include <iostream>

struct myStruct {
  int x;
  int y;
  char c;
  bool b;
};

int main() {
  myStruct s;
  s.x = 5;
  s.y = 10;
  s.c = 'a';
  s.b = true;

  int *p = reinterpret_cast<int *>(&s);
  std::cout << *p << std::endl;
  p++;
  std::cout << *p << std::endl;
  p++;
  std::cout << reinterpret_cast<char *>(p) << std::endl;
  p++;
  std::cout << *p << std::endl;
  std::cout << sizeof(bool) << std::endl;
}
