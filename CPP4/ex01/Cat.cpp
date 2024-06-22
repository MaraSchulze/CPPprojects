/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:03:34 by marschul          #+#    #+#             */
/*   Updated: 2024/02/22 19:05:17 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() {
	Animal::type = "cat";
	brain = new Brain();
    std::cout << "Cat constructor" << std::endl;
}

Cat::~Cat() {
	delete brain;
    std::cout << "Cat destructor" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	brain = new Brain(*other.brain);
    std::cout << "Cat copy constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
        std::cout << "Cat assignment operator" << std::endl;
    }
    return *this;
}

void Cat::makeSound() const {
	std::cout << "Mienz, mienz, miouw." << std::endl;
}

void	Cat::setThought(std::string thought, int i) {
	if (i >= 0 && i < 100)
		brain->setIdea(thought, i);
}

std::string	Cat::getThought(int i) const {
	if (i >= 0 && i < 100)
		return brain->getIdea(i);
	else
		return 0;
}
