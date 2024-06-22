/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:59:05 by marschul          #+#    #+#             */
/*   Updated: 2024/02/10 13:11:08 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main() {
	std::string	monsterName("Monster");
	std::string	maraName("Mara");
	ClapTrap	monster(monsterName);
	ScavTrap	mara(maraName);

	monster.attack("Mara");
	mara.attack("Monster");
	mara.beRepaired(10);
	mara.guardGate();
	return 0;
}
