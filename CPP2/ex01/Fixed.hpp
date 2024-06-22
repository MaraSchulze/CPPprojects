/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:07:26 by marschul          #+#    #+#             */
/*   Updated: 2024/01/20 14:58:52 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class	Fixed {
	private:
		int					_value;
		static const int	_fractionalBits = 8;
		int					intToFixed(int intNumber);
		int					floatToFixed(float floatNumber);
	public:
		Fixed();
		Fixed(int const number);
		Fixed(float const number);
		Fixed(const Fixed& other);
		Fixed& 	operator=(const Fixed& other);
		int 	getRawBits() const;
		void 	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		~Fixed();
};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixedObj);

#endif