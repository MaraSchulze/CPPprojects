/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:03:34 by marschul          #+#    #+#             */
/*   Updated: 2024/02/22 19:08:22 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() {
	AAnimal::type = "cat";
	brain = new Brain();
    std::cout << "Cat constructor" << std::endl;
}

Cat::~Cat() {
	delete brain;
    std::cout << "Cat destructor" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other) {
	brain = new Brain(*other.brain);
    std::cout << "Cat copy constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        AAnimal::operator=(other);
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
	brain->setIdea(thought, i);
}

std::string	Cat::getThought(int i) const {
	return brain->getIdea(i);
}
