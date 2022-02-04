#ifndef FORM_HPP
# define FORM_HPP

#include <exception>
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form
{
    private:
        static int const k_max_grade = 1;
        static int const k_min_grade = 150;

        std::string const _name;
        bool _is_signed;
        int const _grade_to_sign;
        int const _grade_to_execute;
        std::string _target;

    public:
        Form(std::string const &name = "default_form", int const grade_to_sign = k_min_grade, int const grade_to_execute = k_min_grade, std::string const &target = "default_target");
        virtual ~Form();
        Form(Form const &other);
        Form &operator=(Form const &other);

        static void assertGradeInRange(int grade);
        void assertExecutable(Bureaucrat const &executer) const;
        std::string const & getName() const;
        int getSignGrade() const;
        int getExecuteGrade() const;
        bool isSigned() const;
        std::string const & getTarget() const;

        virtual bool beSigned(Bureaucrat const &bureaucrat);
        virtual bool execute(Bureaucrat const &executor) const = 0;

        class GradeTooHighException: public std::out_of_range
        {
            public:
                GradeTooHighException(const std::string &message = "Grade is too high");
        };

        class GradeTooLowException: public std::out_of_range
        {
            public:
                GradeTooLowException(const std::string &message = "Grade is too low");
        };
        
        class FormIsSignedException: public std::invalid_argument
        {
            public:
                FormIsSignedException(const std::string &message = "Form is already signed");
        };

        class NoSignException: public std::invalid_argument
        {
            public:
                NoSignException(const std::string &message = "Form is not signed yet");
        };
};

std::ostream &operator<<(std::ostream &ost, Form const &rhs);

#endif
