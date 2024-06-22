/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:59:26 by marschul          #+#    #+#             */
/*   Updated: 2024/01/17 13:12:45 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

class	HumanA {
	private:
		std::string	_name;
		Weapon&		_weapon;
	public:
		HumanA(std::string name, Weapon& weapon);
		void	attack(void) const;
};
