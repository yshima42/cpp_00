#include "Intern.hpp"

Intern::InvalidFormNameException::InvalidFormNameException(const std::string &message) : std::invalid_argument(message) {}

Intern::Intern()
{ 
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &other)
{
    *this = other;
}

Intern &Intern::operator=(Intern const &other)
{
    (void)other;
    return *this;
}

Form *(*Intern::formFunction[])(const std::string &target) = {
    NULL, makeShrubberyCreationForm, makeRobotomyRequestForm, Intern::makePresidentialPardonForm,
};

int Intern::checkIndex(std::string const &form_name)
{
    int index = (form_name == "shrubbery creation") + (form_name == "robotomy request") * 2 +
                (form_name == "presidential pardon") * 3;
    return index;
}

Form *Intern::makeForm(const std::string &form_name, const std::string &target) const
{
    int index = checkIndex(form_name);
    while (index == 0)
        throw InvalidFormNameException();
    std::cout << GREEN << "Intern creates " << form_name << " form"<< RESET << std::endl;
    return formFunction[index](target);
}

Form *Intern::makeShrubberyCreationForm(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

Form *Intern::makeRobotomyRequestForm(const std::string &target) 
{
    return new RobotomyRequestForm(target);
}

Form *Intern::makePresidentialPardonForm(const std::string &target) 
{
    return new PresidentialPardonForm(target);
}

