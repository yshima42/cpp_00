#include <iostream>

int main()
{
	int num;

	std::cin >> num;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
	}
	std::cout << num << std::endl;
	return 0;
}
