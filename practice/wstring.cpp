#include <iostream>
#include <string>

int main()
{
    std::wstring str1(L"abcdああ");
    std::wstring str2;

    str2 = str1;
    std::wcout << str2 << std::endl;
}
