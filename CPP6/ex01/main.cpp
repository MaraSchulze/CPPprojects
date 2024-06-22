/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:29:29 by marschul          #+#    #+#             */
/*   Updated: 2024/03/12 18:44:39 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	main() {
	Data	testData;

	testData.a = 1;
	testData.b = 2;
	std::cout << std::hex << "before Serialization	" << &testData << std::endl;
	std::cout << std::hex << "after Serialization	" << Serializer::deserialize(Serializer::serialize(&testData)) << std::endl;
}