/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:34:29 by marschul          #+#    #+#             */
/*   Updated: 2024/03/15 10:49:21 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int	main( void ) {
	// test ints
	Array<int>	intArray(5);

	for (int i = 0; i < 5; i++) {
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;

	// test strings
	Array<std::string>	stringArray(5);

	for (int i = 0; i < 5; i++) {
		stringArray[i] = std::string("a");
	}
	for (int i = 0; i < 5; i++) {
		std::cout << stringArray[i] << " ";
	}
	std::cout << std::endl;

	// testing deep copy
	Array<std::string>	cloneArray = stringArray;

	cloneArray[1] = std::string("z");
	for (int i = 0; i < 5; i++) {
		std::cout << cloneArray[i] << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << stringArray[i] << " ";
	}
	std::cout << std::endl;

	// testing assignment operator. Should handle different sizes.
	Array<int> a(5);
	a = Array<int>(2);
	return 0; 
}
