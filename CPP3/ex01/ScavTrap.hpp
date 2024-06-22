/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:01:32 by marschul          #+#    #+#             */
/*   Updated: 2024/02/10 13:09:47 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(std::string& name);
	    ScavTrap(const ScavTrap& other);
	    ~ScavTrap();
    	ScavTrap&	operator=(const ScavTrap& other);
		void 		attack(const std::string& target);
		void 		guardGate(void);
};

#endif
