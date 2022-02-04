#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::GradeTooHighException::GradeTooHighException(const std::string &message) : std::out_of_range(message) {}

Form::GradeTooLowException::GradeTooLowException(const std::string &message) : std::out_of_range(message) {}

Form::FormIsSignedException::FormIsSignedException(const std::string &message) : std::invalid_argument(message) {}

Form::NoSignException::NoSignException(const std::string &message) : std::invalid_argument(message) {}


Form::Form(std::string const &name, int const grade_to_sign, int const grade_to_execute, std::string const &target)
     : _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute), _target(target)
{
    assertGradeInRange(_grade_to_sign);
    assertGradeInRange(_grade_to_execute);
}

Form::~Form()
{
}

Form::Form(Form const &other)
    : _name(other._name), _is_signed(other._is_signed), _grade_to_sign(other._grade_to_sign), _grade_to_execute(other._grade_to_execute), _target(other._target)
{
}

Form &Form::operator=(Form const &other)
{
    const_cast<std::string&>(_name) = other._name;
    _is_signed = other._is_signed;
    const_cast<int&>(_grade_to_sign) = other._grade_to_sign;
    const_cast<int&>(_grade_to_execute) = other._grade_to_execute;
    _target = other._target;
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

std::string const & Form::getTarget() const
{
    return this->_target;
}

void Form::assertGradeInRange(int grade)
{
    if (grade < k_max_grade)
        throw GradeTooHighException();
    else if (grade > k_min_grade)
        throw GradeTooLowException();
}

void Form::assertExecutable(Bureaucrat const &executer) const
{
    if (this->_grade_to_execute < executer.getGrade())
        throw GradeTooLowException("Grade is too low to execute");
    else if (!this->_is_signed)
        throw NoSignException("Form is not signed yet");
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
        << "Is Signed    : " << (rhs.isSigned() ? "True" : "False") << "\n"
        << "Target       : " << rhs.getTarget() << "\n";
    return ost;
}
