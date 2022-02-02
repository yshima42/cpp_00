#include "Form.hpp"

Form::Form()
{
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
    }
    return *this;
}
