/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:24:39 by pafuente          #+#    #+#             */
/*   Updated: 2026/03/05 12:24:39 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    std::cout << "\n=== CREAR BUREAUCRATS ===\n";
    Bureaucrat boss("Boss", 1);
    Bureaucrat worker("Worker", 140);

    std::cout << boss << std::endl;
    std::cout << worker << std::endl;

    std::cout << "\n=== SHRUBBERY TEST ===\n";

    ShrubberyCreationForm shrub("home");

    worker.signForm(shrub);
    worker.executeForm(shrub);

    boss.executeForm(shrub);

    std::cout << "\n=== ROBOTOMY TEST ===\n";

    RobotomyRequestForm robot("Bender");

    worker.signForm(robot);     // debería fallar
    boss.signForm(robot);

    worker.executeForm(robot);  // debería fallar
    boss.executeForm(robot);

    std::cout << "\n=== PRESIDENTIAL TEST ===\n";

    PresidentialPardonForm pardon("Arthur Dent");

    worker.signForm(pardon);   // falla
    boss.signForm(pardon);

    worker.executeForm(pardon); // falla
    boss.executeForm(pardon);

    std::cout << "\n=== EXECUTE UNSIGNED FORM ===\n";

    ShrubberyCreationForm test("garden");
    boss.executeForm(test); // debería fallar (no firmado)

    return 0;
}