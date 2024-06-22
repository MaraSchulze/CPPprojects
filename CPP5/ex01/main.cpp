/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:09:58 by marschul          #+#    #+#             */
/*   Updated: 2024/03/06 12:06:55 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main() {
    Bureaucrat bureaucrat;
    Form form;

	try {
		bureaucrat = Bureaucrat("Olaf Scholz", 2);
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		form = Form("Resignment", 1, 2);
	} catch (const Form::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
	} catch (const Form::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	}

	bureaucrat.signForm(form);
}
