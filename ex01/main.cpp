/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 09:41:16 by edi-maio          #+#    #+#             */
/*   Updated: 2026/05/08 10:05:10 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat alice("Alice", 2);
    Bureaucrat bob("Bob", 149);
    Form topSecret("TopSecret", 1, 30);
    Form lowLevel("LowLevel", 150, 150);

    std::cout << alice << "\n" << bob << "\n";
    std::cout << topSecret << "\n" << lowLevel << "\n";

    alice.incrementGrade();
    bob.decrementGrade();
    std::cout << alice << "\n" << bob << "\n";

    alice.signForm(topSecret);
    bob.signForm(topSecret);
    bob.signForm(lowLevel);
    std::cout << topSecret << "\n" << lowLevel << "\n";

    Form copyForm = lowLevel;
    copyForm.beSigned(alice);
    std::cout << copyForm << "\n";

    Bureaucrat copyBob("CopyBob", 100);
    copyBob = alice;
    std::cout << copyBob << "\n";

    Form assignmentForm("Assignment", 50, 50);
    assignmentForm = topSecret;
    std::cout << assignmentForm << "\n";

    try { Bureaucrat tooHigh("X", 0); }
    catch (std::exception& e) { std::cerr << e.what() << "\n"; }

    try { Bureaucrat tooLow("Y", 151); }
    catch (std::exception& e) { std::cerr << e.what() << "\n"; }

    try { alice.incrementGrade(); }
    catch (std::exception& e) { std::cerr << e.what() << "\n"; }

    try { bob.decrementGrade(); }
    catch (std::exception& e) { std::cerr << e.what() << "\n"; }
}
