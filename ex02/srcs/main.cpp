/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 09:41:16 by edi-maio          #+#    #+#             */
/*   Updated: 2026/05/08 11:10:45 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat alice("Alice", 1);
    Bureaucrat bob("Bob", 150);

    ShrubberyCreationForm   s("home");
    RobotomyRequestForm     r("Bender");
    PresidentialPardonForm  p("Zaphod");

    std::cout << alice << "\n" << bob << "\n";
    std::cout << s << "\n" << r << "\n" << p << "\n";

    alice.signForm(s);
    alice.executeForm(s);

    alice.signForm(r);
    alice.executeForm(r);

    alice.signForm(p);
    alice.executeForm(p);

    bob.signForm(s);
    bob.signForm(r);
    bob.signForm(p);

    ShrubberyCreationForm s2("garden");
    try { alice.executeForm(s2); }
    catch (std::exception& e) { std::cerr << e.what() << "\n"; }

    ShrubberyCreationForm s3("park");
    alice.signForm(s3);
    try { bob.executeForm(s3); }
    catch (std::exception& e) { std::cerr << e.what() << "\n"; }
}
