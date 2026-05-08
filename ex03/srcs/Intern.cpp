/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:01:55 by edi-maio          #+#    #+#             */
/*   Updated: 2026/05/08 11:13:11 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

Intern::Intern()
{
    std::cout << "Intern created" << std::endl;
}

Intern::Intern(const Intern& other)
{
    (void)other;
    std::cout << "Intern copied" << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern destroyed" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    std::cout << "Intern assigned" << std::endl;
    return *this;
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
    
    std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int formIndex = -1;

    for (int i = 0; i < 3 && formIndex == -1; i++)
        if (formName == formNames[i])
            formIndex = i;
    switch (formIndex)
    {
        case 0:
            return new ShrubberyCreationForm(target);
        case 1:
            return new RobotomyRequestForm(target);
        case 2:
            return new PresidentialPardonForm(target);
        default:
            std::cerr << "Form not found" << std::endl;
            return (NULL);
    }
}