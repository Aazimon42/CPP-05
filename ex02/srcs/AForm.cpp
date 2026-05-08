/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 10:16:34 by edi-maio          #+#    #+#             */
/*   Updated: 2026/05/08 10:54:35 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

AForm::AForm() : name("Default"), signGrade(150), execGrade(150)
{
    this->isSigned = false;
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int executeGrade) : name(name), signGrade(signGrade), execGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw AForm::GradeTooHighException();
    else if (signGrade > 150 || executeGrade > 150)
        throw AForm::GradeTooLowException();
    this->isSigned = false;
    std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(const AForm& other) : name(other.name), signGrade(other.signGrade), execGrade(other.execGrade)
{
    this->isSigned = other.isSigned;
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
    std::cout << "AForm copy assignment operator called" << std::endl;
    this->isSigned = other.isSigned;
    return *this;
}

AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}

std::string AForm::getName() const
{
    return name;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int AForm::getSignGrade() const
{
    return signGrade;
}

int AForm::getExecGrade() const
{
    return execGrade;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > signGrade)
        throw AForm::GradeTooLowException();
    if (isSigned)
        throw AForm::AlreadySignedException();
    isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << "AForm " << form.getName() << ", sign grade " << form.getSignGrade() << ", execute grade " << form.getExecGrade() << ", is signed: " << (form.getIsSigned() ? "yes" : "no") << ".";
    return os;
}