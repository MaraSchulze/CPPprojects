/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:40:34 by marschul          #+#    #+#             */
/*   Updated: 2024/01/19 20:51:44 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class	Weapon {
	private:
		std::string	_type;
	public:
		Weapon(void);
		Weapon(std::string type);
		const std::string&	getType(void) const;
		void		setType(std::string);
};

#endif
