/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:59:47 by marschul          #+#    #+#             */
/*   Updated: 2024/03/13 18:21:23 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
typename T::iterator	easyfind(T& container, int element) {
	typename T::iterator it = std::find(container.begin(), container.end(), element);
	return it;
}
