/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:59:05 by marschul          #+#    #+#             */
/*   Updated: 2024/02/10 13:12:38 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int	main() {
	std::string name1("Monster");
	std::string name2("Peter");

	ClapTrap		clappy(name1);
	FragTrap		fraggy(name2);

	clappy.attack(name2);
	fraggy.attack(name1);
	fraggy.beRepaired(20);
	fraggy.highFivesGuys();
	return 0;
}
