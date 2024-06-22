/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:13:13 by marschul          #+#    #+#             */
/*   Updated: 2024/02/13 15:47:01 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() {
    std::cout << "Animal constructor" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "Animal copy constructor" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        type = other.type;
        std::cout << "Animal assignment operator" << std::endl;
    }
    return *this;
}

void 	Animal::makeSound() const {
	std::cout << "Makes default animal sound." << std::endl;
}

std::string	Animal::getType(void) const {
	return (Animal::type);
}
