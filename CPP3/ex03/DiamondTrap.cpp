/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:24:06 by marschul          #+#    #+#             */
/*   Updated: 2024/02/10 13:30:34 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : name("Default") {
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap Standard Constructor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string& name) : ClapTrap(name), ScavTrap(name), FragTrap(name), name(name) {
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
	ClapTrap::name = ClapTrap::name + "_clap_name";
	std::cout << "DiamondTrap Constructor" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(name), ScavTrap(name), FragTrap(name), name(other.name) {
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	std::cout << "DiamondTrap Copy Constructor" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap Destructor" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other) {
		this->name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
	}
	return (*this);}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
	std::cout << "My name is " << name << " and also " << ClapTrap::name << "! I'm confused as well..." << std::endl;
}
