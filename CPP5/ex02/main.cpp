/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:09:58 by marschul          #+#    #+#             */
/*   Updated: 2024/03/07 15:45:52 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int	main() {
	Bureaucrat	*bureaucrat;
	try {
		bureaucrat = new Bureaucrat("Olaf Scholz", 2);
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	}

	ShrubberyCreationForm	scf("test");
	RobotomyRequestForm		rrf("looney");
	PresidentialPardonForm	ppf("Arthur");

	scf.beSigned(*bureaucrat);
	rrf.beSigned(*bureaucrat);
	ppf.beSigned(*bureaucrat);

	bureaucrat->executeForm(scf);
	bureaucrat->executeForm(rrf);
	bureaucrat->executeForm(ppf);
}
