/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:46:18 by marschul          #+#    #+#             */
/*   Updated: 2024/03/04 10:48:28 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("Robotomy Request", false, 72, 45, "") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Robotomy Request", false, 72, 45, target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

void PresidentialPardonForm::execute_action() const {
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
