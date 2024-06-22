/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:11:51 by marschul          #+#    #+#             */
/*   Updated: 2024/03/06 12:06:01 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form() : name("Defaultform"), isSigned(false), requiredGradeToSign(150), requiredGradeToExecute(150) {}

Form::Form(const std::string& name, int requiredGradeToSign, int requiredGradeToExecute)
	: name(name), isSigned(false), requiredGradeToSign(requiredGradeToSign), requiredGradeToExecute(requiredGradeToExecute) {
    if (requiredGradeToSign < 1 || requiredGradeToExecute < 1) {
        throw GradeTooHighException();
    } else if (requiredGradeToSign > 150 || requiredGradeToExecute > 150) {
        throw GradeTooLowException();
    }
}

Form::Form(const Form& other)
	: name(other.name), isSigned(other.isSigned), requiredGradeToSign(other.requiredGradeToSign), requiredGradeToExecute(other.requiredGradeToExecute) {}

Form::~Form() {}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        this->isSigned = other.isSigned;
    }
    return *this;
}

const std::string& Form::getName() const {
    return name;
}

bool Form::getIsSigned() const {
    return isSigned;
}

int Form::getRequiredGradeToSign() const {
    return requiredGradeToSign;
}

int Form::getRequiredGradeToExecute() const {
    return requiredGradeToExecute;
}

void Form::beSigned(Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > requiredGradeToSign)
		throw GradeTooLowException();
	else
    	isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "GradeTooHighException";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "GradeTooLowException";
}

std::ostream &operator<<(std::ostream &out, const Form& form) {
    out << "Form " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No") << ", Required grade to sign: "
        << form.getRequiredGradeToSign() << ", Required grade to execute: " << form.getRequiredGradeToExecute();
    return out;
}
