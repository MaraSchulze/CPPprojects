/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:20:40 by marschul          #+#    #+#             */
/*   Updated: 2024/01/17 18:16:58 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl	harl = Harl();	
	
	if (argc == 2)
		harl.complain(argv[1]);
	else
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}