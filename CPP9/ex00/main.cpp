/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:38:50 by marschul          #+#    #+#             */
/*   Updated: 2024/03/27 19:06:53 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int	main(int argc, char **argv) {
	BitcoinExchange btc = BitcoinExchange();

	if (argc != 2) {
		std::cerr << "Usage: ./btc <filename>" << std::endl;
		return 1;
	}
	
	// read in prices
	if (btc.readInPrices() == false)
		return 1;

	// read in orders
	if (btc.readInOrders(argv[1]) == false)
		return 1;

	// trade
	btc.trade();
}
