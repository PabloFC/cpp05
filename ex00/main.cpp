#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    // =========================================================
    // TEST 1: Normal creation and display
    // =========================================================
    std::cout << "\n--- Valid creation ---" << std::endl;
    try
    {
        Bureaucrat alicia("Alicia", 5);
        Bureaucrat bobo("Bobo", 150);
        std::cout << alicia << std::endl;
        std::cout << bobo << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    // =========================================================
    // TEST 2: incrementGrade normal and GradeTooHigh exception
    // =========================================================
    std::cout << "\n--- incrementGrade -> GradeTooHighException ---" << std::endl;
    try
    {
        Bureaucrat carol("Carol", 2);
        std::cout << carol << std::endl;

        carol.incrementGrade(); // grade goes from 2 to 1
        std::cout << carol << std::endl;

        carol.incrementGrade();          // already at 1 -> exception
        std::cout << carol << std::endl; // should not reach here
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // =========================================================
    // TEST 3: decrementGrade normal and GradeTooLow exception
    // =========================================================
    std::cout << "\n--- decrementGrade -> GradeTooLowException ---" << std::endl;
    try
    {
        Bureaucrat david("David", 149);
        std::cout << david << std::endl;

        david.decrementGrade(); // grade goes from 149 to 150
        std::cout << david << std::endl;

        david.decrementGrade();          // already at 150 -> exception
        std::cout << david << std::endl; // should not reach here
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // =========================================================
    // TEST 4: Construction with grade too high (< 1)
    // =========================================================
    std::cout << "\n--- Construction with grade 0 -> GradeTooHighException ---" << std::endl;
    try
    {
        Bureaucrat eva("Eva", 0);      // exception in constructor
        std::cout << eva << std::endl; // should not reach here
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // =========================================================
    // TEST 5: Construction with grade too low (> 150)
    // =========================================================
    std::cout << "\n--- Construction with grade 151 -> GradeTooLowException ---" << std::endl;
    try
    {
        Bureaucrat fran("Fran", 151);   // exception in constructor
        std::cout << fran << std::endl; // should not reach here
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    return 0;
}