/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:13:32 by marschul          #+#    #+#             */
/*   Updated: 2024/02/22 19:39:10 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _nrMaterias(0) {}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < _nrMaterias; i++)
		delete _materias[i];
}

MateriaSource::MateriaSource(const MateriaSource& other) : _nrMaterias(other._nrMaterias) {
	for (int i = 0; i < 4; ++i) {
		if (other._materias[i] != NULL) {
			_materias[i] = other._materias[i]->clone();
		} else {
			_materias[i] = NULL;
		}
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            delete _materias[i];
        }
        _nrMaterias = other._nrMaterias;
        for (int i = 0; i < _nrMaterias; ++i) {
            _materias[i] = other._materias[i]->clone();
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* materia) {
	if (_nrMaterias < 4)
	{
		_materias[_nrMaterias] = materia;
		_nrMaterias++;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < _nrMaterias; i++) {
		if (type == _materias[i]->getType())
			return _materias[i]->clone();
	}
    return NULL;
}
