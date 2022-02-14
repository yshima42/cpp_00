#include "color.hpp"
#include "whatever.hpp"

void testSubject() {
  int a = 2;
  int b = 3;

  ::swap(a, b);
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
  std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

  std::string c = "chaine1";
  std::string d = "chaine2";

  ::swap(c, d);
  std::cout << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
  std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
  std::cout << std::endl;
}

void test() {
  char a = 'a';
  char b = 'b';
  float f1 = 1.1f;
  float f2 = 2.2f;
  double d1 = 1.1;
  double d2 = 2.2;
  bool b1 = true;
  bool b2 = false;

  std::cout << "a: " << a << ", b: " << b << std::endl;
  ::swap(a, b);
  std::cout << "a: " << a << ", b: " << b << std::endl;
  std::cout << "min: " << ::min(a, b) << std::endl;
  std::cout << "max: " << ::max(a, b) << std::endl;
  std::cout << std::endl;

  std::cout << "f1: " << f1 << ", f2: " << f2 << std::endl;
  ::swap(f1, f2);
  std::cout << "f1: " << f1 << ", f2: " << f2 << std::endl;
  std::cout << "min: " << ::min(f1, f2) << std::endl;
  std::cout << "max: " << ::max(f1, f2) << std::endl;
  std::cout << std::endl;

  std::cout << "d1: " << d1 << ", d2: " << d2 << std::endl;
  ::swap(d1, d2);
  std::cout << "d1: " << d1 << ", d2: " << d2 << std::endl;
  std::cout << "min: " << ::min(d1, d2) << std::endl;
  std::cout << "max: " << ::max(d1, d2) << std::endl;
  std::cout << std::endl;

  std::cout << "b1: " << b1 << ", b2: " << b2 << std::endl;
  ::swap(b1, b2);
  std::cout << "b1: " << b1 << ", b2: " << b2 << std::endl;
  std::cout << "min: " << ::min(b1, b2) << std::endl;
  std::cout << "max: " << ::max(b1, b2) << std::endl;
  std::cout << std::endl;
}

int main() {
  testSubject();
  test();
}
