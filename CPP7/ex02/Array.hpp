/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:57:18 by marschul          #+#    #+#             */
/*   Updated: 2024/03/13 16:01:31 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class  Array {
	private:
		int	_size;
		T	*_array;

	public:
		Array();
		Array(int size);
		Array(const Array& other);
		~Array();
		Array&		operator=(const Array& other);
		T& 			operator[](int index) const;
		int			size(void) const;
};

#include "Array.tpp"

#endif
