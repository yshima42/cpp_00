#ifndef INTERN_HPP
# define INTERN_HPP

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Form.hpp"
#include "color.hpp"

class Intern
{
    public:

        enum e_form
        {
            UNDEFINED,
            SCForm,
            RRForm,
            PPForm,
            k_form_num
        };

        Intern();
        virtual ~Intern();
        Intern(Intern const &other);
        Intern &operator=(Intern const &other);

        static const std::string form_list[k_form_num];
        static Form* (*formFunction[k_form_num])(const std::string &target);
        
        static int checkIndex(std::string const &form_name);
        Form* makeForm(std::string const &form_name, std::string const &target) const;

        static Form *makeUndefinedForm(const std::string &target);
        static Form *makeShrubberyCreationForm(const std::string &target);
        static Form *makeRobotomyRequestForm(const std::string &target);
        static Form *makePresidentialPardonForm(const std::string &target);

        class InvalidFormNameException : public std::invalid_argument
        {
            public:
                InvalidFormNameException(const std::string &message = "Error: Intern recieved invalid argument");
        };
};

#endif
