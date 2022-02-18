#include <algorithm>
#include <array>
#include <functional>
#include <iostream>

int main() {
  std::array<int, 10> s = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};

  // デフォルトの < 演算子を使ってソートします。
  std::sort(s.begin(), s.end());
  for (auto a : s) {
    std::cout << a << " ";
  }
  std::cout << '\n';

  // 標準ライブラリの比較関数オブジェクトを使ってソートします。
  std::sort(s.begin(), s.end(), std::greater<int>());
  for (auto a : s) {
    std::cout << a << " ";
  }
  std::cout << '\n';

  // カスタム関数オブジェクトを使ってソートします。
  struct {
    bool operator()(int a, int b) const { return a < b; }
  } customLess;
  std::sort(s.begin(), s.end(), customLess);
  for (auto a : s) {
    std::cout << a << " ";
  }
  std::cout << '\n';

  // ラムダ式を使ってソートします。
    std::sort(s.begin(), s.end(), [](int a, int b) {
        return a > b;
});
for (auto a : s) {
  std::cout << a << " ";
}
std::cout << '\n';
{}
