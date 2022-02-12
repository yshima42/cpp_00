#include <iostream>

using namespace std;
// MultiFunc に渡されたデータの種類
enum EMFType
{
    MF_INT,     // 符号付き整数
    MF_UINT,    // 符号無し整数
    MF_FLOAT,   // 単精度小数へのポインタ
    MF_DOUBLE,  // 倍精度小数へのポインタ
    MF_STRING,  // 文字列
};

// いろいろなデータを１つの関数で表示します
void MultiFunc(EMFType type, unsigned int data)
{
    switch(type)
    {
    case MF_INT   : cout << (int)data            << endl; break;
    case MF_UINT  : cout << data                 << endl; break;
    case MF_FLOAT : cout << *(const float*)data  << endl; break;
    case MF_DOUBLE: cout << *(const double*)data << endl; break;
    case MF_STRING: cout << (const char*)data    << endl; break;
    }
}

int main()
{
    int          a = -10;
    unsigned int b = -10;
    float        c = -10.3f;
    double       d = 3.1415926538979;
    const char*  e = "えいっ";

    MultiFunc(MF_INT   , a);
    MultiFunc(MF_UINT  , b);
    MultiFunc(MF_FLOAT , (unsigned int)&c);
    MultiFunc(MF_DOUBLE, (unsigned int)&d);
    MultiFunc(MF_STRING, (unsigned int)e);

    return 0;
}
