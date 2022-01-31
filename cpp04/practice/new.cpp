#include <iostream>

using namespace std;

void out_of_memory()
{
    cerr << "メモリ割り当てに失敗しました。" << endl;
    throw bad_alloc();
}

int main()
{
    set_new_handler(out_of_memory);

    int *ptr, n;

    cout << "割り当てるメモリサイズを入力してください：" << endl;  
    n = -1;
    ptr = new int[n];

    cout << "メモリサイズは： " << n * sizeof(int)
         << " バイトです。" << endl;


    delete [] ptr;
    cout << "メモリを解放しました。" << endl;

    return 0;
}
