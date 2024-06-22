/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:24:48 by marschul          #+#    #+#             */
/*   Updated: 2024/02/10 12:57:03 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() {
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap Standard Constructor" << std::endl;
}

FragTrap::FragTrap(std::string& name) : ClapTrap(name) {
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap Constructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	std::cout << "FragTrap Copy Constructor" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap Destructor" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		this->name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
	}
	return (*this);
}

void FragTrap::attack(const std::string& target) {
	if (energyPoints > 0 && hitPoints > 0)
	{
		energyPoints--;
    	std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	}
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << name << " requests high five now! FragTrap " << name << " just being positive." << std::endl;
}
