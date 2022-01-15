#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::ifstream ifs("hello.txt");
    if (!ifs) {
        std::cerr << "ファイルオープンに失敗" << std::endl;
        std::exit(1);
    }

    std::string buf;
    std::getline(ifs, buf);
    if (!ifs) {
        std::cerr << "読み込みに失敗" << std::endl;
        std::exit(1);
    }

    std::cout << buf << std::endl;
}
