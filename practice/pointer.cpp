#include <sstring>

int main()
{
    int num;
    std::sstream stream;
    stream << std::hex << std::uppercase << &num;
    // stream.str() でstringを取得する
    std::cout << stream.str() << std::endl();
}