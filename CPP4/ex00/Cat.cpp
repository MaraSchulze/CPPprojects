/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:03:34 by marschul          #+#    #+#             */
/*   Updated: 2024/02/22 16:06:08 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("cat") {
    std::cout << "Cat constructor" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destructor" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
        std::cout << "Cat assignment operator" << std::endl;
    }
    return *this;
}

void Cat::makeSound() const {
	std::cout << "Mienz, mienz, miouw." << std::endl;
}
