#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target)
    : Form("ShrubberyCreation", k_grade_to_sign, k_grade_to_exec, target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
    : Form(other)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
    this->Form::operator=(other);
    return *this;
}

bool ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    assertExecutable(executor);
    std::string filename = this->getTarget() + "_shrubbery";
    std::ofstream ofs(filename);
    if (ofs.fail())
        throw "Fail to open file";
    ofs <<  "     ccee88oo          " << std::endl
        <<  "  C8O8O8Q8PoOb o8oo    " << std::endl
        <<  " dOB69QO8PdUOpugoO9bD  " << std::endl
        <<  "CgggbU8OU qOp qOdoUOdcb" << std::endl
        <<  "    6OuU  /p u gcoUodpP" << std::endl
        <<  "      \\\\\\//  /douUP    " << std::endl
        <<  "        \\\\\\////   o    " << std::endl
        <<  "         |||/\\   OOO   " << std::endl
        <<  "         |||\\/  opppo  " << std::endl
        <<  "         |||||    |    " << std::endl
        <<  "   .....//||||\\...|..  " << std::endl;
    return true;
}
