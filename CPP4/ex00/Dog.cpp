/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:22:12 by marschul          #+#    #+#             */
/*   Updated: 2024/02/22 16:06:49 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("dog") {
    std::cout << "Dog constructor" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog destructor" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copy constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        std::cout << "Dog assignment operator" << std::endl;
    }
    return *this;
}

void Dog::makeSound() const {
	std::cout << "Wuff, wuff, bark." << std::endl;
}
