#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Form.hpp"

class PresidentialPardonForm: public Form
{
    private:
        static const int k_grade_to_sign = 25;
        static const int k_grade_to_exec = 5;

    public:
        PresidentialPardonForm(std::string const &target = "default_target");
        virtual ~PresidentialPardonForm();
        PresidentialPardonForm(PresidentialPardonForm const &other);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &other);

        virtual bool execute(Bureaucrat const & executor) const;
};

#endif
