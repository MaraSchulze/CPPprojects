/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:22:12 by marschul          #+#    #+#             */
/*   Updated: 2024/02/22 19:08:31 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() {
	AAnimal::type = "dog";
	brain = new Brain();
    std::cout << "Dog constructor" << std::endl;
}

Dog::~Dog() {
	delete brain;
    std::cout << "Dog destructor" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other) {
	brain = new Brain(*other.brain);
    std::cout << "Dog copy constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        AAnimal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
        std::cout << "Dog assignment operator" << std::endl;
    }
    return *this;
}

void Dog::makeSound() const {
	std::cout << "Wuff, wuff, bark." << std::endl;
}

void	Dog::setThought(std::string thought, int i) {
	brain->setIdea(thought, i);
}

std::string	Dog::getThought(int i) const {
	return brain->getIdea(i);
}
