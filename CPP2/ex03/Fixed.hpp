/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:07:26 by marschul          #+#    #+#             */
/*   Updated: 2024/01/22 14:06:13 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class	Fixed {
	private:
		int					_value;
		static const int	_fractionalBits = 8;
		int					_intToFixed(int intNumber);
		int					_floatToFixed(float floatNumber);
	public:
		Fixed();
		Fixed(int const number);
		Fixed(float const number);
		Fixed(const Fixed& other);
		static Fixed& 		min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& 		max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
		Fixed& 				operator=(const Fixed& other);
		int 				getRawBits() const;
		void 				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;
		bool 				operator>(const Fixed& other) const;
		bool 				operator<(const Fixed& other) const;
		bool				operator>=(const Fixed& other) const;
		bool 				operator<=(const Fixed& other) const;
		bool 				operator==(const Fixed& other) const;
		bool 				operator!=(const Fixed& other) const;
		Fixed 				operator+(const Fixed& other) const;
		Fixed 				operator-(const Fixed& other) const;
		Fixed 				operator*(const Fixed& other) const;
		Fixed 				operator/(const Fixed& other) const;
		Fixed& 				operator++();
		Fixed 				operator++(int);
		Fixed& 				operator--();
		Fixed 				operator--(int);
		~Fixed();
};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixedObj);

#endif