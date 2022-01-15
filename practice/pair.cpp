#include <iostream>
#include <utility>

int main()
{
    typedef std::pair<int, double> mypair;

    mypair a;                 // 各要素のデフォルトコンストラクタで初期化
    mypair b(10, 3.5);        // 初期値を与える
    mypair c(b);              // 他の pair から生成 (コピーコンストラクタ)

    std::cout << a.first << ", " << a.second << "\n"
              << b.first << ", " << b.second << "\n"
              << c.first << ", " << c.second << std::endl;
}
