/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:40:17 by marschul          #+#    #+#             */
/*   Updated: 2024/02/22 14:42:33 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

#ifndef ICE_H
# define ICE_H

# include <string>

class Ice : public AMateria {
	public:
		Ice(void);
		Ice(std::string const & type);
		~Ice(void);
    	Ice(const Ice& other);
    	Ice& operator=(const Ice& other);
		Ice* clone(void) const;
		void use(ICharacter& target);
};

#endif
