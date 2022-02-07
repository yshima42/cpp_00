#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Form.hpp"
#include "color.hpp"

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

void say(std::string const & str)
{
    std::cout << std::endl << str << std::endl;
}

void test()
{
    //Bureaucrat b0("b0", 0);
    Bureaucrat b1("b1", 1);
    Bureaucrat b2("b2", 2);
    Bureaucrat b4("b4", 4);
    Bureaucrat b5("b5", 5);
    Bureaucrat b6("b6", 6);
    Bureaucrat b24("b24", 24);
    Bureaucrat b25("b25", 25);
    Bureaucrat b26("b26", 26);
    Bureaucrat b44("b44", 44);
    Bureaucrat b45("b45", 45);
    Bureaucrat b46("b46", 46);
    Bureaucrat b71("b71", 71);
    Bureaucrat b72("b72", 72);
    Bureaucrat b73("b73", 73);
    Bureaucrat b136("b136", 136);
    Bureaucrat b137("b137", 137);
    Bureaucrat b138("b138", 138);
    Bureaucrat b144("b144", 144);
    Bureaucrat b145("b145", 145);
    Bureaucrat b146("b146", 146);
    Bureaucrat b149("b149", 149);
    Bureaucrat b150("b150", 150);
    //Bureaucrat b151("b151", 151);

    ShrubberyCreationForm sf("target_sf");
    ShrubberyCreationForm sf_copy(sf);
    ShrubberyCreationForm sf_copy2 = sf;
    RobotomyRequestForm rf("target_rf");
    RobotomyRequestForm rf_copy(rf);
    RobotomyRequestForm rf_copy2 = rf;
    PresidentialPardonForm pf("target_pf");
    PresidentialPardonForm pf_copy(pf);
    PresidentialPardonForm pf_copy2 = pf;

    try 
    {
        say("< Copy Check >");
        std::cout << sf << "\n" << sf_copy << "\n" << sf_copy2 << std::endl;
        std::cout << rf << "\n" << rf_copy << "\n" << rf_copy2 << std::endl;
        std::cout << pf << "\n" << pf_copy << "\n" << pf_copy2 << std::endl;

        say("< ShrubberyCreationForm(145 to sign, 137 to exec) >");
        b146.signForm(sf);
        b138.executeForm(sf);
        b137.executeForm(sf);
        b145.signForm(sf);
        b138.executeForm(sf);
        b137.executeForm(sf);

        say("< RobotomyRequestForm(72 to sign, 45 to exec) >");
        b73.signForm(rf);
        b46.executeForm(rf);
        b45.executeForm(rf);
        b72.signForm(rf);
        b46.executeForm(rf);
        b45.executeForm(rf);

        say("< PresidentialPardonForm(25 to sign, 5 to exec) >");
        b26.signForm(pf);
        b6.executeForm(pf);
        b5.executeForm(pf);
        b25.signForm(pf);
        b6.executeForm(pf);
        b5.executeForm(pf);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

}


int	main()
{
    //testStandard();
    //testLow();
    //testHigh();

    test();
}

//void detect_leak(void) __attribute__((destructor));

//void detect_leak(void) { system("leaks -q a.out"); }
