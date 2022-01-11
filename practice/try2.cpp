#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	try{
		int num1;
		cout << "enter first number: " << endl;
		cin >> num1;

		int num2;
		cout << "enter second: " << endl;
		cin >> num2;

		if (num2 == 0){
			throw 0;
		}

		cout << num1/num2 << endl;

	} catch (...) {
		cout << "you cant devide by 0" << endl;
	}

}