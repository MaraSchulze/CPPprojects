/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:07:45 by marschul          #+#    #+#             */
/*   Updated: 2024/04/11 19:52:47 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {
	RPN	rpn = RPN();

	if (argc != 2) {
		std::cout << "Usage: ./RPN <expression>" << std::endl;
		return 1;
	}
	if (rpn.readIn(argv[1]) == false)
		return 1;
	rpn.calculate();
}
