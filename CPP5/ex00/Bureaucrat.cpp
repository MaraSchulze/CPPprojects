/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:47:20 by marschul          #+#    #+#             */
/*   Updated: 2024/03/06 11:50:24 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Defaultbureaucrat"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {
	if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		_grade = other.getGrade();
	}
    return *this;
}

const std::string& Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade() {
	if (_grade <= 1) {
        throw GradeTooHighException();
    }
	else
		_grade -= 1;
}

void Bureaucrat::decreaseGrade() {
	if (_grade >= 150) {
        throw GradeTooLowException();
    }
	else
		_grade += 1;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "GradeTooHighException";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "GradeTooLowException";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}
