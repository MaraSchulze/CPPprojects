/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:35:44 by marschul          #+#    #+#             */
/*   Updated: 2024/02/22 14:42:45 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

#ifndef CURE_H
# define CURE_H

# include <string>

class Cure : public AMateria {
	public:
		Cure(void);
		Cure(std::string const & type);
		~Cure(void);
    	Cure(const Cure& other);
    	Cure& operator=(const Cure& other);
		Cure* clone(void) const;
		void use(ICharacter& target);
};

#endif
