/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:49:07 by marschul          #+#    #+#             */
/*   Updated: 2024/03/15 10:40:59 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename T>
void	iter(T *array, size_t n, void (*f)(T&)) {
	for (size_t i = 0; i < n; i++) {
		f(array[i]);
	}
}

#endif
