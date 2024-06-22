/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:07:26 by marschul          #+#    #+#             */
/*   Updated: 2024/01/22 10:00:20 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

class	Fixed {
	private:
		int					_value;
		static int const	_fractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& 				operator=(const Fixed& other);
		~Fixed();
		int 				getRawBits() const;
		void 				setRawBits(int const raw);
};

#endif