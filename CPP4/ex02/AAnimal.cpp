/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:13:13 by marschul          #+#    #+#             */
/*   Updated: 2024/02/13 15:47:01 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal() {
    std::cout << "AAnimal constructor" << std::endl;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal destructor" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type) {
    std::cout << "AAnimal copy constructor" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    if (this != &other) {
        type = other.type;
        std::cout << "AAnimal assignment operator" << std::endl;
    }
    return *this;
}

void 	AAnimal::makeSound() const {
	std::cout << "Makes default animal sound." << std::endl;
}

std::string	AAnimal::getType(void) const {
	return (AAnimal::type);
}
