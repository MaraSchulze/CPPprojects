/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:50:57 by marschul          #+#    #+#             */
/*   Updated: 2024/01/17 19:45:08 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

class	HumanB {
	private:
		std::string	_name;
		Weapon		*_weapon;
	public:
		HumanB(std::string name);
		void	attack(void) const;
		void	setWeapon(Weapon& weapon);
};
