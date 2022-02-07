#include "PresidentialPardonForm.hpp"
#include "Form.hpp"
#include "color.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
    : Form("Presidential_Pardon_Form", k_grade_to_sign, k_grade_to_exec, target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other)
    : Form(other)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
    this->Form::operator=(other);
    return *this;
}

bool PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    assertExecutable(executor);
    std::cout << YELLOW << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << RESET << std::endl;
    return true;
}
