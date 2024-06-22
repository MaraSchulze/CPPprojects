/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:36:19 by marschul          #+#    #+#             */
/*   Updated: 2024/03/12 21:42:30 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
T max(T a, T b) {
	if (a == b)
		return b;
    if (a > b)
		return a;
	else
		return b;
}

template <typename T>
T min(T a, T b) {
	if (a == b)
		return b;
    if (a < b)
		return a;
	else
		return b;
}

template <typename T>
void swap(T& a, T& b) {
	T	temp;

	temp = a;
	a = b;
	b = temp;
}

#endif
