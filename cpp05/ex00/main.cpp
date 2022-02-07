#include "Bureaucrat.hpp"
#include <chrono>
#include <string>


void testStandard()
{
    std::cout << "---testStandard---" << std::endl;
	int	test[] = {-2147483648,0,1,149,150,151,2147483647};

	for (int i = 0; i < 8; ++i)
	{
		int n = test[i];
		try
		{
			Bureaucrat a("a", n);
			Bureaucrat b("b");
			b = a;
		}
		catch (std::exception const & e)
		{
			std::cout << e.what() << " " << n << std::endl;
		}
	}
}

void testLow()
{
    std::cout << "---testLow---" << std::endl;
    try
    {
        Bureaucrat c("c", 149);
        std::cout << c << std::endl;
        c.incrementGrade();
        std::cout << c << std::endl;
        c.decrementGrade();
        std::cout << c << std::endl;
        c.decrementGrade();
        std::cout << c << std::endl;
        c.decrementGrade();
        std::cout << c << std::endl;
    }
    catch (std::exception const & e)
    {
		std::cout << e.what() << std::endl; 
    }
}

void testHigh()
{
    std::cout << "---testHigh---" << std::endl;
    try
    {
        Bureaucrat c("c", 2);
        std::cout << c << std::endl;
        c.decrementGrade();
        std::cout << c << std::endl;
        c.incrementGrade();
        std::cout << c << std::endl;
        c.incrementGrade();
        std::cout << c << std::endl;
        c.incrementGrade();
        std::cout << c << std::endl;
    }
    catch (std::exception const & e)
    {
		std::cout << e.what() << std::endl; 
    }
}



int	main()
{
    testStandard();
    testLow();
    testHigh();
}

// void detect_leak(void) __attribute__((destructor));

// void detect_leak(void) { system("leaks -q a.out"); }
