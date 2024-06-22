/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:45:34 by marschul          #+#    #+#             */
/*   Updated: 2024/02/10 13:20:44 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string	name;
	public:
		DiamondTrap();
		DiamondTrap(std::string& name);
	    DiamondTrap(const DiamondTrap& other);
	    ~DiamondTrap();
    	DiamondTrap&	operator=(const DiamondTrap& other);
		void 			attack(const std::string& target);
		void 			whoAmI(void);
};

#endif
