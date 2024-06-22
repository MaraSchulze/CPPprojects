/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:22:59 by marschul          #+#    #+#             */
/*   Updated: 2024/01/27 11:24:06 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap {
	public:
		FragTrap();
		FragTrap(std::string& name);
	    FragTrap(const FragTrap& other);
	    ~FragTrap();
    	FragTrap&	operator=(const FragTrap& other);
		void 		attack(const std::string& target);
		void 		highFivesGuys(void);
};

#endif
