#include "Bureaucrat.hpp"
#include "Form.hpp"


void testStandard()
{
    std::cout << "---testStandard---" << std::endl;
	int	test[] = {-2147483648,0,1,149,150,151,2147483647};

	for (int i = 0; i < 8; i++)
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
			std::cout << e.what() << " " << n<< std::endl;
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

void testFormOutput()
{
    try {
        Bureaucrat b;
        Form f;
        std::cout << b << std::endl;
        std::cout << f << std::endl;
    } catch (std::exception const & e) {
        std::cout << e.what() << std::endl;
    }
}

void testForm()
{
  
    std::cout << "---test---" << std::endl; 
    Bureaucrat a("a", 3);
    std::cout << a << std::endl;
    try 
    {
        Form f("f", 4, 10);
        std::cout << f << std::endl;
        a.signForm(f);
        std::cout << f << std::endl;
        a.signForm(f);
        std::cout << std::endl;

        Form f2("f2", 3, 10);
        std::cout << f2 << std::endl;
        a.signForm(f2);
        std::cout << f2 << std::endl;
        a.signForm(f2);
        std::cout << std::endl; 
        
        Form f3("f3", 2, 10);
        std::cout << f3 << std::endl;
        a.signForm(f3);
        std::cout << f3 << std::endl;
        a.signForm(f3);
        std::cout << std::endl; 
     }
    catch (std::exception const & e) 
    {
        std::cout << e.what() << " " << 1 << std::endl;
    }
}

int	main()
{
    //testStandard();
    //testLow();
    //testHigh();
    
    //testFormOutput();
    testForm();
}

// void detect_leak(void) __attribute__((destructor));

// void detect_leak(void) { system("leaks -q a.out"); }
