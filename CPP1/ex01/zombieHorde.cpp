/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:48:25 by marschul          #+#    #+#             */
/*   Updated: 2024/01/17 19:09:47 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <stdlib.h>

Zombie*	zombieHorde(int N, std::string name) {
	Zombie	*horde;

	horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i] = Zombie(name);
	return horde;
}
