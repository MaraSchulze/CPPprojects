/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:11:51 by marschul          #+#    #+#             */
/*   Updated: 2024/02/29 22:44:55 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm() : name("default"), isSigned(false), requiredGradeToSign(150), requiredGradeToExecute(150) {}

AForm::AForm(const std::string& name, bool isSigned, int requiredGradeToSign, int requiredGradeToExecute, const std::string& target)
	: name(name), isSigned(isSigned), requiredGradeToSign(requiredGradeToSign), requiredGradeToExecute(requiredGradeToExecute), target(target) {
    if (requiredGradeToSign < 1 || requiredGradeToExecute < 1) {
        throw GradeTooHighException();
    } else if (requiredGradeToSign > 150 || requiredGradeToExecute > 150) {
        throw GradeTooLowException();
    }
}

AForm::AForm(const AForm& other)
	: name(other.name), isSigned(other.isSigned), requiredGradeToSign(other.requiredGradeToSign), requiredGradeToExecute(other.requiredGradeToExecute), target(other.target) {}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        this->isSigned = other.isSigned;
    }
    return *this;
}

const std::string& AForm::getName() const {
    return name;
}

bool AForm::getIsSigned() const {
    return isSigned;
}

const std::string&	AForm::getTarget() const {
	return target;
}


int AForm::getRequiredGradeToSign() const {
    return requiredGradeToSign;
}

int AForm::getRequiredGradeToExecute() const {
    return requiredGradeToExecute;
}

bool AForm::beSigned(Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > requiredGradeToSign)
		return false;
	else {
    	isSigned = true;
		return true;
	}	
}

void	AForm::execute(Bureaucrat const & executor) const {
	if (! getIsSigned())
		throw NotSignedException();
	if (executor.getGrade() > getRequiredGradeToExecute())
		throw GradeTooLowException();
	this->execute_action();
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "GradeTooHighException";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "GradeTooLowException";
}

const char* AForm::NotSignedException::what() const throw() {
    return "NotSignedException";
}

std::ostream &operator<<(std::ostream &out, const AForm& form) {
    out << "Form " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No") << ", Required grade to sign: "
        << form.getRequiredGradeToSign() << ", Required grade to execute: " << form.getRequiredGradeToExecute();
    return out;
}
