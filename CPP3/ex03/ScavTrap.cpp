/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:01:44 by marschul          #+#    #+#             */
/*   Updated: 2024/02/10 13:10:11 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() {
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap Standard Constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string& name) : ClapTrap(name) {
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap Constructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	std::cout << "ScavTrap Copy Constructor" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Destructor" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		this->name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
	}
	return (*this);
}

void ScavTrap::attack(const std::string& target) {
	if (energyPoints > 0 && hitPoints > 0)
	{
		energyPoints--;
    	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	}
}

void ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << name << " guards the gate now!" << std::endl;
}

