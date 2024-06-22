/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:13:02 by marschul          #+#    #+#             */
/*   Updated: 2024/01/22 20:51:36 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

int	Fixed::_intToFixed(int intNumber) {
	return intNumber << _fractionalBits;
}

int	Fixed::_floatToFixed(float floatNumber) {
	int	fixedNumber;

	floatNumber = floatNumber * (1 << _fractionalBits);
	fixedNumber = static_cast<int>(roundf(floatNumber));
	return fixedNumber;
}

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number) : _value(_intToFixed(number)) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float number) : _value(_floatToFixed(number)) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _value(other._value) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return a < b ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return a < b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return a > b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return a > b ? a : b;
}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		this->setRawBits(other.getRawBits());
		std::cout << "Copy assignment operator called" << std::endl;
	}
	return *this;
}

bool Fixed::operator>(const Fixed& other) const {
    return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed& other) const {
    return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const {
    return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->getRawBits() != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed& other) const {
    int 	rawSum = this->getRawBits() + other.getRawBits();
	Fixed	fixedNumber;

	fixedNumber.setRawBits(rawSum);
	return fixedNumber;
}

Fixed Fixed::operator-(const Fixed& other) const {
    int 	rawSum = this->getRawBits() - other.getRawBits();
	Fixed	fixedNumber;

	fixedNumber.setRawBits(rawSum);
	return fixedNumber;}

Fixed Fixed::operator*(const Fixed& other) const {
    int 	rawProduct = this->getRawBits() * other.getRawBits();
	Fixed	fixedNumber = Fixed();

	fixedNumber.setRawBits(rawProduct >> _fractionalBits);
	return fixedNumber;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed	fixedNumber = Fixed();
	int		result;

	if (other.getRawBits() != 0) {
		result = this->getRawBits() / other.getRawBits();
		fixedNumber.setRawBits(result);
	}
	return fixedNumber;
}

Fixed& Fixed::operator++() {
    setRawBits(getRawBits() + 1);
	return *this;
}
Fixed Fixed::operator++(int) {
	Fixed	old = *this;

    setRawBits(getRawBits() + 1);
	return old;
}

Fixed& Fixed::operator--() {
    setRawBits(getRawBits() - 1);
	return *this;}

Fixed Fixed::operator--(int) {
	Fixed	old = *this;

    setRawBits(getRawBits() - 1);
	return old;}

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

	floatNumber = static_cast<float>(_value) / (1 << _fractionalBits);
	return floatNumber;
}

int		Fixed::toInt(void) const {
	return _value >> _fractionalBits;
}

std::ostream& operator<<(std::ostream &out, const Fixed &obj) {
	out << obj.toFloat();
	return out;
}
