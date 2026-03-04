#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat a("Alice", 50);
    Form f("Contract", 40, 30);

    std::cout << a << std::endl;
    std::cout << f << std::endl;

    a.signForm(f);

    Bureaucrat b("Bob", 30);
    b.signForm(f);

    std::cout << f << std::endl;

    return 0;
}