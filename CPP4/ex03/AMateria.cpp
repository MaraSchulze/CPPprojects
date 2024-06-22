/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:28:51 by marschul          #+#    #+#             */
/*   Updated: 2024/02/22 19:13:50 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#include <string>
#include <iostream>

AMateria::AMateria() {}

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(const AMateria& other) : _type(other.getType()) {}

AMateria::~AMateria(void) {}

AMateria&	AMateria::operator=(const AMateria& other) {
	(void) other;
    return *this;
}

std::string const & AMateria::getType() const {
	return _type;
}

void 	AMateria::use(ICharacter& target) {
	(void) target;
}
