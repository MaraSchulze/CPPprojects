/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:21:52 by marschul          #+#    #+#             */
/*   Updated: 2024/02/22 19:13:59 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
# define AMATERIA_H

# include <string>

class ICharacter;

class AMateria
{
	protected:
		std::string	_type;
	public:
		AMateria();
		AMateria(std::string const & type);
		virtual ~AMateria(void);
    	AMateria(const AMateria& other);
    	AMateria& 			operator=(const AMateria& other);
		std::string const & getType() const;
		virtual AMateria* 	clone() const = 0;
		virtual void 		use(ICharacter& target);
};

#endif
