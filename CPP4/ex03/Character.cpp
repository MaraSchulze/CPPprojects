/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:36:59 by marschul          #+#    #+#             */
/*   Updated: 2024/02/22 21:13:49 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

#include <string>

Character::Character() : _nr_used(0), _nrTrash(0) {}

Character::~Character() {
	for (int i = 0; i < _nrTrash; i++)
		delete _trash[i];
	delete[] _trash;
	for (int i = 0; i < _nr_used; i++)
		delete _materias[i];
}

Character::Character(std::string name) : _name(name),  _nr_used(0), _trash(NULL), _nrTrash(0) {}

Character::Character(const Character& other) :_name(other._name),  _nr_used(other._nr_used), _trash(NULL), _nrTrash(other._nrTrash) {
	for (int i = 0; i < _nr_used; i++)
		_materias[i] = other._materias[i]->clone();
}

Character&	Character::operator=(const Character& other) {
	if (this != &other) {
		for (int i = 0; i < _nr_used; i++)
			_materias[i] = other._materias[i]->clone();
	}
	return *this;
}

void	Character::empty(int idx) {
	AMateria	**old;

	_trash = new AMateria*[_nrTrash + 1];
	if (_nrTrash != 0) {
		old = _trash;
		for (int i = 0; i < _nrTrash; i++)
			_trash[i] = old[i];
		delete[] old;
	}
	_trash[_nrTrash] = _materias[idx];
	_nrTrash++;
}

std::string const & Character::getName() const {
	return _name;
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < _nr_used)
		_materias[idx]->use(target);
}

void	Character::equip(AMateria* m) {
	if (_nr_used < 4)
	{
		_materias[_nr_used] = m;
		_nr_used++;
	}
}

void 	Character::unequip(int idx) {
	if (idx >= 0 && idx < _nr_used)
	{
		empty(idx);
		for (int i = idx + 1; i < _nr_used; i++)
			_materias[i - 1] = _materias[i];
		_nr_used--;
	}
}
