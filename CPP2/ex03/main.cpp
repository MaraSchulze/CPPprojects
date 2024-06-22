/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:05:16 by marschul          #+#    #+#             */
/*   Updated: 2024/01/22 14:36:05 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int	main(void) { 
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(5.0f, 5.0f);
	Point point(5.0f, 5.0f);

	std::cout << (bsp(a, b, c, point) ? "yes" : "no") << std::endl;
	return 0; 
}