/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:34:29 by marschul          #+#    #+#             */
/*   Updated: 2024/03/15 10:40:38 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "test.hpp"
#include <iostream>
#include <string>

void	square(int& i) {
	i = i * i;
}

int	main( void ) {
	// Test 1
	int	array[5] = {1, 2, 3, 4, 5};

	::iter(array, 5, square);
	for (int i = 0; i < 5; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;

	// Test 2
    void (*concatStrPtr)(std::string&) = concat<std::string>;
	std::string	stringArray[5] = {"a", "b", "c", "d", "e"};

	::iter(stringArray, 5, concatStrPtr);
	for (int i = 0; i < 5; i++) {
		std::cout << stringArray[i] << " ";
	}
	std::cout << std::endl;

	return 0; 
}
