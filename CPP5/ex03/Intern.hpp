/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:20:00 by marschul          #+#    #+#             */
/*   Updated: 2024/03/04 12:22:37 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern {
public:
    Intern();
    Intern(const Intern& other);
    ~Intern();
    Intern&	operator=(const Intern& other);
	AForm	*makeForm(std::string formName, std::string target);
};

#endif
