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
    // Create two bureaucrats: boss (grade 1, can do everything) and worker (grade 140, very limited)
    std::cout << "\n=== CREATE BUREAUCRATS ===\n";
    Bureaucrat boss("Boss", 1);
    Bureaucrat worker("Worker", 140);

    std::cout << boss << std::endl;
    std::cout << worker << std::endl;

    // ShrubberyCreationForm: requires grade <=145 to sign, <=137 to execute
    // Worker can sign but not execute; boss executes successfully
    std::cout << "\n=== SHRUBBERY TEST ===\n";

    ShrubberyCreationForm shrub("home");

    worker.signForm(shrub);    // succeeds (140 <= 145)
    worker.executeForm(shrub); // fails (140 > 137)

    boss.executeForm(shrub); // succeeds after boss signs it

    // RobotomyRequestForm: requires grade <=72 to sign, <=45 to execute
    // Worker fails both; boss succeeds both (50% chance of robotomy)
    std::cout << "\n=== ROBOTOMY TEST ===\n";

    RobotomyRequestForm robot("Bender");

    worker.signForm(robot); // fails (140 > 72)
    boss.signForm(robot);   // succeeds

    worker.executeForm(robot); // fails (140 > 45)
    boss.executeForm(robot);   // succeeds

    // PresidentialPardonForm: requires grade <=25 to sign, <=5 to execute
    // Only boss can sign and execute it
    std::cout << "\n=== PRESIDENTIAL TEST ===\n";

    PresidentialPardonForm pardon("Arthur Dent");

    worker.signForm(pardon); // fails (140 > 25)
    boss.signForm(pardon);   // succeeds

    worker.executeForm(pardon); // fails (140 > 5)
    boss.executeForm(pardon);   // succeeds

    // Trying to execute an unsigned form must throw FormNotSignedException
    std::cout << "\n=== EXECUTE UNSIGNED FORM ===\n";

    ShrubberyCreationForm test("garden");
    boss.executeForm(test); // fails: form not signed

    return 0;
}
