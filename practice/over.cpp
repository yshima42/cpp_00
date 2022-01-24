#include <iostream>

class Number
{
private:
    int value_;
public:
    Number(int value);
    ~Number();
    
    // +演算子のオーバーロード
    Number operator+(Number number)
    {
        return Number(value_ + number.value_);
    }

    int getValue() const
    {
        return value_;
    }
};

Number::Number(int value) : value_(value) {} // コンストラクタ
Number::~Number() {} // デストラクタ

int main()
{
    Number num(5);
    Number sum = num + Number(1);

    std::cout << sum.getValue() << std::endl; // 6が出力される
}
