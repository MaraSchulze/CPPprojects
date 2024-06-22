/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:09:58 by marschul          #+#    #+#             */
/*   Updated: 2024/03/06 11:35:48 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	main() {
	try {
		Bureaucrat bureaucrat("Olaf Scholz", 151);
		std::cout << bureaucrat << " arrived in the Bundestag!" << std::endl;
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Bureaucrat bureaucrat("Christian Lindner", 33);
		std::cout << bureaucrat << " arrived in the Bundestag!" << std::endl;
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	}
}
