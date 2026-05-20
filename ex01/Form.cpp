/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 09:54:16 by edi-maio          #+#    #+#             */
/*   Updated: 2026/05/20 21:36:43 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default"), signGrade(150), execGrade(150)
{
    this->isSigned = false;
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int signGrade, int executeGrade) : name(name), signGrade(signGrade), execGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw Form::GradeTooHighException();
    else if (signGrade > 150 || executeGrade > 150)
        throw Form::GradeTooLowException();
    this->isSigned = false;
    std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form& other) : name(other.name), signGrade(other.signGrade), execGrade(other.execGrade)
{
    this->isSigned = other.isSigned;
    std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other)
{
    std::cout << "Form copy assignment operator called" << std::endl;
    this->isSigned = other.isSigned;
    return *this;
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName() const
{
    return name;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

int Form::getSignGrade() const
{
    return signGrade;
}

int Form::getExecGrade() const
{
    return execGrade;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > signGrade)
        throw Form::GradeTooLowException();
    if (isSigned)
        throw Form::AlreadySignedException();
    isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form " << form.getName() << ", sign grade " << form.getSignGrade() << ", execute grade " << form.getExecGrade() << ", is signed: " << (form.getIsSigned() ? "yes" : "no") << ".";
    return os;
}