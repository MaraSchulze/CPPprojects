/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:23:35 by marschul          #+#    #+#             */
/*   Updated: 2024/02/22 19:09:26 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>

int main() {

	AAnimal		*animals[6];
	std::string	dogThought = "I am a dog";
	std::string	anotherDogThought = "I am also a dog";
	std::string	catThought = "I am a cat";
	Dog			doggie2;

	// constructing
	for (int i = 0; i < 6; i++) {
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	// using the brain
	animals[0]->setThought(dogThought, 0);
	animals[1]->setThought(catThought, 0);
	std::cout << animals[0]->getThought(0) << std::endl;
	std::cout << animals[1]->getThought(0) << std::endl;

	// testing deep copy
	doggie2 = *(Dog *) animals[0];
	doggie2.setThought(anotherDogThought, 0);
	std::cout << doggie2.getThought(0) << std::endl;
	std::cout << "Now dog 0 again: " << animals[0]->getThought(0) << std::endl;

	// deleting
	for (int i = 0; i < 6; i++) {
		delete animals[i];
	}
	return 0; 
}
