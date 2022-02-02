#ifndef FORM_HPP
# define FORM_HPP

class Form
{
    private:

    public:
        Form();
        virtual ~Form();
        Form(Form const &other);
        Form &operator=(Form const &other);
};

#endif
