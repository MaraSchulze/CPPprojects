/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 06:50:41 by marschul          #+#    #+#             */
/*   Updated: 2024/01/15 17:35:21 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <stdlib.h>

int main() {
	Zombie	*horde;
	int		N;
	
	N = 10;
    horde = zombieHorde(N, "Alberto");
	if (horde == NULL)
		return (1);
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
    return 0;
}