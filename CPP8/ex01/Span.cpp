/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:37:39 by marschul          #+#    #+#             */
/*   Updated: 2024/03/19 12:37:08 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <exception>
#include <iostream>

Span::Span() : _vec(std::vector<int>()), _size(0) {}

Span::Span(int n) : _vec(std::vector<int>()), _size(n) {}

Span::Span(const Span& other) : _vec(other._vec), _size(other._size) {}

Span::~Span() {}

Span&	Span::operator=(const Span& other) {
	if (this != &other) {
		_vec = other._vec;
		_size = other._size;
	}
	return *this;
}

void	Span::addNumber(int number) {
	if ((int) _vec.size() >= _size)
		throw Span::SizeException();
	_vec.push_back(number);
}

int		Span::shortestSpan(void) {
	int							min;
	int							span;

	// Throw exception if size is 0 or 1
	if (_vec.size() < 2)
		throw Span::NoSpanException();

	// sort vector and find out smallest span
	std::sort(_vec.begin(), _vec.end());
	min = longestSpan();
	for (std::vector<int>::iterator it = _vec.begin() + 1; it != _vec.end(); it++) {
		span = *it - *(it - 1);
    	min =  span < min ? span : min;
    }
	return min;
}

int		Span::longestSpan(void) {
	std::vector<int>::iterator min;
	std::vector<int>::iterator max;

	// Throw exception if size is 0 or 1
	if (_vec.size() < 2)
		throw Span::NoSpanException();
	
	// Return difference between min and max of the vector
	min = std::min_element(_vec.begin(), _vec.end());
	max = std::max_element(_vec.begin(), _vec.end());
	return *max - *min;
}

const char* Span::SizeException::what() const throw() {
	return "Size exceeded exception";
}

const char* Span::NoSpanException::what() const throw() {
	return "Size exceeded exception";
}
