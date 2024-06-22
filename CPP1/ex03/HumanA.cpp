/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:59:01 by marschul          #+#    #+#             */
/*   Updated: 2024/01/17 13:13:13 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <string>
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {}

void	HumanA::attack(void) const {
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}