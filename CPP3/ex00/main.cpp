/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:59:05 by marschul          #+#    #+#             */
/*   Updated: 2024/02/10 12:43:21 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main() {
	std::string	monsterName("Monster");
	std::string	maraName("Mara");
	ClapTrap	monster(monsterName);
	ClapTrap	mara(maraName);

	monster.attack("Mara");
	mara.takeDamage(0);
	mara.beRepaired(10);
	return 0;
}
