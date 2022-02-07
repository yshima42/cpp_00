#include "RobotomyRequestForm.hpp"
#include "color.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const & target)
    : Form("RobotomyRequest", RobotomyRequestForm::k_grade_to_sign, RobotomyRequestForm::k_grade_to_exec, target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
    : Form(other)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
    this->Form::operator=(other);
    return *this;
}

bool RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    assertExecutable(executor);
    std::cout << YELLOW << "Rizzzzzzzzzzzzzz... " << this->getTarget() << "has been robotomized successfully 50% of the time" << RESET << std::endl;
    srand(time(NULL));
    int random_num = rand() % 2;
    if (random_num == 0)
        std::cout << YELLOW << "Success: " << this->getTarget() << " has been robotomized" << RESET << std::endl;
    else
        std::cout << YELLOW << "Falure: " << this->getTarget() << " is broken" << RESET << std::endl;
    return true;
}
