/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 06:40:19 by marschul          #+#    #+#             */
/*   Updated: 2024/01/08 06:41:04 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "Zombie.hpp"

void	randomChump(std::string name) {
    Zombie	zombie(name);
    zombie.announce();
}