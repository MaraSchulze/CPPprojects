/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:36:35 by marschul          #+#    #+#             */
/*   Updated: 2024/02/22 15:51:36 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

#include <iostream>

Cure::Cure(void) : AMateria("cure") {}

Cure::Cure(std::string const & type) : AMateria(type) {}

Cure::~Cure() {}

Cure::Cure(const Cure& other) : AMateria(other) {}

Cure& Cure::operator=(const Cure& other) {
	(void) other;
    return *this;
}

Cure*	Cure::clone() const {
	return new Cure(_type);
}

void 	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
