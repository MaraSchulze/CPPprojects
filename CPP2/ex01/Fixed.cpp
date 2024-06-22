/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:13:02 by marschul          #+#    #+#             */
/*   Updated: 2024/01/22 10:31:26 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

int	Fixed::intToFixed(int intNumber) {
	return intNumber << _fractionalBits;
}

int	Fixed::floatToFixed(float floatNumber) {
	int	fixedNumber;

	floatNumber = floatNumber * (1 << _fractionalBits);
	fixedNumber = static_cast<int>(roundf(floatNumber));
	return fixedNumber;
}

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number) : _value(intToFixed(number)) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float number) : _value(floatToFixed(number)) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _value(other.getRawBits()) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		_value = other.getRawBits();
		std::cout << "Copy assignment operator called" << std::endl;
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	return _value;
}

void Fixed::setRawBits(int const raw) {
	_value = raw;
}

float	Fixed::toFloat(void) const {
	float	floatNumber;

	floatNumber = static_cast<float>(getRawBits()) / (1 << _fractionalBits);
	return floatNumber;
}

int		Fixed::toInt(void) const {
	return getRawBits() >> _fractionalBits;
}

std::ostream& operator<<(std::ostream &out, const Fixed &obj) {
	out << obj.toFloat();
	return out;
}
