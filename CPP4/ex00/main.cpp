/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:23:35 by marschul          #+#    #+#             */
/*   Updated: 2024/02/13 15:55:13 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
	const Animal* meta = new Animal(); 
	const Animal* doggie = new Dog();
	const Animal* kitty = new Cat();
	const 	WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongKitty = new WrongCat();

	std::cout << doggie->getType() << " " << std::endl; 
	std::cout << kitty->getType() << " " << std::endl; 
	kitty->makeSound();
	doggie->makeSound();
	meta->makeSound();
	wrongMeta->makeSound();
	wrongKitty->makeSound();
	delete meta;
	delete doggie;
	delete kitty;
	return 0; 
}