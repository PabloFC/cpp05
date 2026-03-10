#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    Intern intern;
    Bureaucrat boss("Boss", 1);

    AForm *f1 = intern.makeForm("shrubbery creation", "home");
    AForm *f2 = intern.makeForm("robotomy request", "Palomo");
    AForm *f3 = intern.makeForm("presidential pardon", "Antonio");
    AForm *f4 = NULL;
    try
    {
        f4 = intern.makeForm("unknown form", "test");
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    if (f1)
    {
        boss.signForm(*f1);
        boss.executeForm(*f1);
        delete f1;
    }

    if (f2)
    {
        boss.signForm(*f2);
        boss.executeForm(*f2);
        delete f2;
    }

    if (f3)
    {
        boss.signForm(*f3);
        boss.executeForm(*f3);
        delete f3;
    }

    if (f4)
    {
        boss.signForm(*f4);
        boss.executeForm(*f4);
        delete f4;
    }

    return 0;
}