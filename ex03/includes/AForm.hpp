/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 09:47:00 by edi-maio          #+#    #+#             */
/*   Updated: 2026/05/08 11:12:19 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>

class Bureaucrat;

class AForm
{
    public:
        AForm();
        AForm(std::string name, int signGrade, int executeGrade);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();
        std::string getName() const;
        bool getIsSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;
        void beSigned(const Bureaucrat& bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;
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
        class AlreadySignedException : public std::exception
        {
            public:
                virtual const char* what() const throw() { return "Form is already signed!"; }
        };
        class NotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw() { return "Form is not signed!"; }
        };
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int execGrade;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif