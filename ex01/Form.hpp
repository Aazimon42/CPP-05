/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 09:47:00 by edi-maio          #+#    #+#             */
/*   Updated: 2026/05/08 10:02:55 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Bureaucrat;

class Form
{
    public:
        Form();
        Form(std::string name, int signGrade, int executeGrade);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();
        std::string getName() const;
        bool getIsSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;
        void beSigned(const Bureaucrat& bureaucrat);
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw() { return "Grade is too high!"; }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw() { return "Grade is too low!"; }
        };
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int execGrade;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif