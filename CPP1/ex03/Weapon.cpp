/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:43:33 by marschul          #+#    #+#             */
/*   Updated: 2024/01/19 20:52:09 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) {}

Weapon::Weapon(std::string type) : _type(type) {}

const std::string&	Weapon::getType(void) const {
	return _type;
}

void	Weapon::setType(std::string type) {
	_type = type;
}