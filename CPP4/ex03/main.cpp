/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:23:35 by marschul          #+#    #+#             */
/*   Updated: 2024/02/22 21:14:28 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#include <iostream>

int main() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice()); 
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice"); 
	me->equip(tmp);
	tmp = src->createMateria("cure"); 
	me->equip(tmp);

	ICharacter* bob = new Character("bob"); 
	me->use(0, *bob);
	me->use(1, *bob);

	// deep copy test
	ICharacter*	meClone = new Character(*(Character *) me);
	meClone->unequip(0);
	meClone->use(0, *bob);

	delete bob; 
	delete me;
	delete src;
	delete meClone;

	return 0; 
}
