/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:34:29 by marschul          #+#    #+#             */
/*   Updated: 2024/03/19 11:40:26 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <iostream>

int	main( void ) { 
	int 						arr[] = {1, 2, 3, 4, 5};
    std::vector<int> 			vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
	int							element = 3;
	int							nonElement = 10;
	std::vector<int>::iterator	output;

	output = easyfind(vec, element);
	if (output != vec.end())
		std::cout << *output << std::endl;
	else
		std::cout << "not found" << std::endl;

	output = easyfind(vec, nonElement);
	if (output != vec.end())
		std::cout << *output << std::endl;
	else
		std::cout << "not found" << std::endl;

	return 0; 
}
