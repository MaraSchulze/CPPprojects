/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:44:01 by marschul          #+#    #+#             */
/*   Updated: 2024/03/08 14:31:21 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: convert <number as string>" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
}