#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "Form.hpp"

class RobotomyRequestForm: public Form
{
    private:
        static const int k_grade_to_sign = 72;
        static const int k_grade_to_exec = 45;

    public:
        RobotomyRequestForm(std::string const &target = "default_target");
        virtual ~RobotomyRequestForm();
        RobotomyRequestForm(RobotomyRequestForm const &other);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &other);

        virtual bool execute(Bureaucrat const & executor) const;
};

#endif
