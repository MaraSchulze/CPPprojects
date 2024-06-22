/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:03:36 by marschul          #+#    #+#             */
/*   Updated: 2024/02/20 21:06:40 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_H
# define IMATERIASOURCE_H

# include "AMateria.hpp"

# include <string>

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void 		learnMateria(AMateria*) = 0;
		virtual AMateria* 	createMateria(std::string const & type) = 0;
};

#endif
