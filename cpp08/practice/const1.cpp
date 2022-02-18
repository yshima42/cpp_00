#include <iostream>

struct Hoge {
  // 非constなメンバ関数
  void a() { std::cout << "non-const" << std::endl; }

  // constなメンバ関数
  void b() const { std::cout << "const" << std::endl; }

  Hoge() {}
};

int main() {
  Hoge hoge;
  hoge.a();  // ok
  hoge.b();  // ok

  const Hoge const_hoge;
  const_hoge.b();  // ok

  return 0;
}
