/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:23:57 by marschul          #+#    #+#             */
/*   Updated: 2024/03/04 12:39:59 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
	*this = other;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& other) {
	if (this != &other)
		*this = other;
    return *this;
}

AForm* Intern::makeForm(std::string formName, std::string target) {
    AForm	*result;
	std::string	formNames[3] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};
	AForm *constructors[] = {
		new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target)
	};

	for (int i = 0; i < 3; i++) {
		if (formName.compare(formNames[i]))
			result = constructors[i];
		else
			delete constructors[i];
	}
    return result;
}
