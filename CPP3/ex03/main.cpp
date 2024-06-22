/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:59:05 by marschul          #+#    #+#             */
/*   Updated: 2024/02/02 21:15:12 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main() {
	std::string	name("Beetle");
	DiamondTrap		thenewman(name);

	thenewman.attack("whatever");
	thenewman.whoAmI();
	return 0;
}
