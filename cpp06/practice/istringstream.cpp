#include <sstream>
#include <iostream>

int main() {
    std::string str = "42a";
    std::istringstream iss(str);

    int num;
    iss >> num;
    std::cout << num << std::endl; // 「42」と表示される
}

