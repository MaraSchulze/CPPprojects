/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:34:29 by marschul          #+#    #+#             */
/*   Updated: 2024/03/19 12:36:35 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>

int main() {
	// Test spans
	Span sp = Span(5);
	sp.addNumber(6); 
	sp.addNumber(3); 
	sp.addNumber(17); 
	sp.addNumber(9); 
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	// Test ranges
	std::vector<int> inputVector = std::vector<int>();
	for (int i = 0; i < 10000; i++) {
		inputVector.push_back(2 * i);
	}
	Span sp2 = Span(10000);
	sp2.addNumberRange(inputVector.begin(), inputVector.end());
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;

	// Test iserting more than n elements
	try {
		sp.addNumber(100);
	} catch (Span::SizeException& e) {
		std::cout << "caught " << e.what() << std::endl;
	}

	return 0;
}
