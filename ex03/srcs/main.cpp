/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 09:41:16 by edi-maio          #+#    #+#             */
/*   Updated: 2026/05/08 11:15:08 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Intern.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat alice("Alice", 1);
    Bureaucrat bob("Bob", 150);

    Intern someRandomIntern;

    AForm* forms[3];
    forms[0] = someRandomIntern.makeForm("shrubbery creation", "home");
    forms[1] = someRandomIntern.makeForm("robotomy request", "Bender");
    forms[2] = someRandomIntern.makeForm("presidential pardon", "Zaphod");

    std::cout << alice << "\n" << bob << "\n";
    for (int i = 0; i < 3; i++)
        std::cout << *forms[i] << "\n";

    for (int i = 0; i < 3; i++)
    {
        alice.signForm(*forms[i]);
        alice.executeForm(*forms[i]);
    }

    for (int i = 0; i < 3; i++)
        bob.signForm(*forms[i]);

    AForm* s2 = someRandomIntern.makeForm("shrubbery creation", "garden");
    try { alice.executeForm(*s2); }
    catch (std::exception& e) { std::cerr << e.what() << "\n"; }

    AForm* s3 = someRandomIntern.makeForm("shrubbery creation", "park");
    alice.signForm(*s3);
    try { bob.executeForm(*s3); }
    catch (std::exception& e) { std::cerr << e.what() << "\n"; }

    try { AForm* f4 = someRandomIntern.makeForm("unknown form", "target"); (void)f4; }
    catch (std::exception& e) { std::cerr << e.what() << "\n"; }

    for (int i = 0; i < 3; i++)
        delete forms[i];
    delete s2;
    delete s3;
}
