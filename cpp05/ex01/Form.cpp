#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::GradeTooHighException::GradeTooHighException(const std::string &message) : std::out_of_range(message) {}

Form::GradeTooLowException::GradeTooLowException(const std::string &message) : std::out_of_range(message) {}

Form::FormIsSignedException::FormIsSignedException(const std::string &message) : std::invalid_argument(message) {}

Form::Form(std::string const &name, int const grade_to_sign, int const grade_to_execute)
     : _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
    assertGradeInRange(_grade_to_sign);
    assertGradeInRange(_grade_to_execute);
}

Form::~Form()
{
}

Form::Form(Form const &other)
{
    *this = other;
}

Form &Form::operator=(Form const &other)
{
    if (this != &other)
    {
        this->_is_signed = other._is_signed;
        this->_grade_to_sign = other._grade_to_sign;
        this->_grade_to_execute = other._grade_to_execute;
    }
    return *this;
}

std::string const & Form::getName() const
{
    return this->_name;
}

int Form::getSignGrade() const
{
    return this->_grade_to_sign;
}

int Form::getExecuteGrade() const
{
    return this->_grade_to_execute;
}

bool Form::isSigned() const
{
    return this->_is_signed;
}

void Form::assertGradeInRange(int grade)
{
    if (grade < k_max_grade)
        throw GradeTooHighException();
    else if (grade > k_min_grade)
        throw GradeTooLowException();
}

bool Form::beSigned(Bureaucrat const &bureaucrat)
{
    if (this->_grade_to_sign < bureaucrat.getGrade())
        throw GradeTooLowException();
    if (this->_is_signed)
        throw FormIsSignedException();
    this->_is_signed = true;
    return true;
}

std::ostream &operator<<(std::ostream &ost, Form const &rhs)
{
    ost << "<Form>\n"
        << "Name         : " << rhs.getName() << "\n"
        << "Sign Grade   : " << rhs.getSignGrade() << "\n"
        << "Execute Grade: " << rhs.getExecuteGrade() << "\n"
        << "Is Signed    : " << (rhs.isSigned() ? "True" : "False");
    return ost;
}
