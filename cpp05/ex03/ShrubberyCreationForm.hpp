#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "Form.hpp"
#include <fstream>
#include <sstream>

class ShrubberyCreationForm: public Form
{
    private:
        static int const k_grade_to_sign = 145;
        static int const k_grade_to_exec = 137;

    public:
        ShrubberyCreationForm(std::string const &target = "default_target");
        virtual ~ShrubberyCreationForm();
        ShrubberyCreationForm(ShrubberyCreationForm const &other);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);

        virtual bool execute(Bureaucrat const & executor) const;
};

#endif
