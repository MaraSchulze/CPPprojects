/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:24:19 by marschul          #+#    #+#             */
/*   Updated: 2024/03/07 15:55:51 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", false, 72, 45, "") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy Request", false, 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

void RobotomyRequestForm::execute_action() const {
	std::cout << "Drrrrrrrrrrrr... ";
    std::srand(std::time(NULL));
   	if (std::rand() % 2 == 0)
		std::cout << getTarget() << " has been successfully robotomized." << std::endl;
	else
		std::cout << getTarget() << " died." << std::endl;
}
