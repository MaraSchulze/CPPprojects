/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:27:55 by marschul          #+#    #+#             */
/*   Updated: 2024/01/19 21:26:42 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void) const {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void) const {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
 << std::endl;
}

void	Harl::warning(void) const {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void) const {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level) const {
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int 		j;

	for (j = 0; j < 4; j++)
	{
		if (levels[j].compare(level) == 0)
			break;
	}
	
	if (j == 4)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return;
	}
	
	while (j <= 4)
	{
		switch (j)
		{
			case 0:
				std::cout << "[ DEBUG ]" << std::endl;;
				Harl::debug();
				std::cout << std::endl;
				break;
			case 1:
				std::cout << "[ INFO ]" << std::endl;;
				Harl::info();
				std::cout << std::endl;
				break;
			case 2:
				std::cout << "[ WARNING ]" << std::endl;;
				Harl::warning();
				std::cout << std::endl;
				break;
			case 3:
				std::cout << "[ ERROR ]" << std::endl;;
				Harl::error();
				std::cout << std::endl;
				break;
		}
		j++;
	}
}