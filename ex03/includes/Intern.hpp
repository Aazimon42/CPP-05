/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 10:58:43 by edi-maio          #+#    #+#             */
/*   Updated: 2026/05/08 11:11:55 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern& other);
        ~Intern();
        Intern& operator=(const Intern& other);
        AForm* makeForm(std::string formName, std::string target);
};

#endif