/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:46:51 by marschul          #+#    #+#             */
/*   Updated: 2024/02/22 16:17:21 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() {
    std::cout << "WrongAnimal constructor" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
    std::cout << "WrongAnimal specialized constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type) {
    std::cout << "WrongAnimal copy constructor" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other) {
        _type = other._type;
        std::cout << "WrongAnimal assignment operator" << std::endl;
    }
    return *this;
}

void 	WrongAnimal::makeSound() const {
	std::cout << "Makes default wrong animal sound." << std::endl;
}

std::string	WrongAnimal::getType(void) const {
	return (WrongAnimal::_type);
}
