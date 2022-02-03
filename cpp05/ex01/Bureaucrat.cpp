#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "color.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &message) : std::out_of_range(message) {}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &message) : std::out_of_range(message) {}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade)
{
    assertGradeInRange(_grade);
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other.getName())
{
    *this = other;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
    if (this != &other)
    {
        _grade = other._grade;
    }
    return *this;
}

std::string const & Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

std::ostream &operator<<(std::ostream &ost, Bureaucrat const &rhs)
{
    ost << "<Bureaucrat>\n"
        << "Name  :" << rhs.getName() << "\n"
        << "Grade :" << rhs.getGrade();
    return ost;
}

void Bureaucrat::assertGradeInRange(int grade)
{
    if (grade < k_max_grade)
    {
        grade = k_max_grade;
        throw GradeTooHighException();
    }
    else if (grade > k_min_grade)
    {
        grade = k_min_grade;
        throw GradeTooLowException();
    }
}

void Bureaucrat::incrementGrade()
{
    assertGradeInRange(_grade - 1);
    this->_grade -= 1;
}

void Bureaucrat::decrementGrade()
{
    assertGradeInRange(_grade + 1);
    this->_grade += 1;
}

bool Bureaucrat::signForm(Form &form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << GREEN << this->getName() << "(Bureaucrat) signs " << form.getName() << "(Form)" << RESET << std::endl;
    }
    catch (std::exception const &e)
    {
        std::cout << RED << this->getName() << "(Bureaucrat) cannot sign " << form.getName() << "(Form) because " << e.what() << RESET << std::endl;
        return false;
    }
    return true;
}

