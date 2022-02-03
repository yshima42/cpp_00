#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    private:
        static int const k_max_grade = 1;
        static int const k_min_grade = 150;

        std::string const _name;
        int _grade;

    public:
        Bureaucrat(std::string const &name = "default", int grade = k_min_grade);
        virtual ~Bureaucrat();
        Bureaucrat(Bureaucrat const &other);
        Bureaucrat &operator=(Bureaucrat const &other);

        std::string const & getName() const;
        int getGrade() const;
        
        void assertGradeInRange(int grade);
        void incrementGrade();
        void decrementGrade();

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
};

std::ostream &operator<<(std::ostream &ost, Bureaucrat const &rhs);

#endif
