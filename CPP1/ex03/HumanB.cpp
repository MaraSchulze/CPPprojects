/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:56:53 by marschul          #+#    #+#             */
/*   Updated: 2024/01/17 19:45:16 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <string>
#include <iostream>

HumanB::HumanB(std::string name)  : _name(name), _weapon(NULL) {}

void	HumanB::attack(void) const {
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon) {
	_weapon = &weapon;
}