/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:44:39 by marschul          #+#    #+#             */
/*   Updated: 2024/02/22 20:28:48 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

#include <iostream>

Ice::Ice() : AMateria("ice") {}

Ice::Ice(std::string const & type) : AMateria(type) {}

Ice::~Ice() {}

Ice::Ice(const Ice& other) : AMateria(other) {}

Ice& Ice::operator=(const Ice& other) {
	(void) other;
    return *this;
}

Ice*	Ice::clone() const {
	Ice	*clone;

	clone = new Ice(_type);
	return clone;
}

void 	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
