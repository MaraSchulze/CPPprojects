/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:47:22 by marschul          #+#    #+#             */
/*   Updated: 2024/02/18 19:32:14 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain constructor" << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << "Brain copy constructor" << std::endl;
	for (int i = 0; i < 100; i++) {
		ideas[i] = other.getIdea(i);
	}
}

Brain::~Brain() {
	std::cout << "Brain destructor" << std::endl;
}

Brain& 	Brain::operator=(const Brain& other) {
    if (this != &other) {
		for (int i = 0; i < 100; i++) {
			ideas[i] = other.getIdea(i);
		}
	}
    return *this;
}

std::string	Brain::getIdea(int i) const {
	return (ideas[i]);
}

void	Brain::setIdea(std::string str, int i) {
	if (i < 100 && i >= 0)
		ideas[i] = str;
}
