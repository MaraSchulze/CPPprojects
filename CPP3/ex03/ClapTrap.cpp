/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:59:05 by marschul          #+#    #+#             */
/*   Updated: 2024/02/10 12:26:01 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0) {
	 std::cout << "ClapTrap Standard Constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	 std::cout << "ClapTrap Constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
	 std::cout << "ClapTrap Copy Constructor" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap Destructor" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		this->name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target) {
	if (energyPoints > 0 && hitPoints > 0)
	{
		energyPoints--;
    	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
    hitPoints = (amount > hitPoints) ? 0 : hitPoints - amount;
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage! Total hit points: " << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (energyPoints > 0 && hitPoints > 0)
	{
    	hitPoints += amount;
		energyPoints--;
    	std::cout << "ClapTrap " << name << " repaired itself for " << amount << " points! Total hit points: " << hitPoints << std::endl;
	}
}
