#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	try{
		int momsAge = 50;
		int sonsAge = 34;

		if (sonsAge > momsAge) {
			throw 99;
		}
	} catch (int x) {
		cout << "son cannot be older than mom, error number: " << x << endl;
	}
}