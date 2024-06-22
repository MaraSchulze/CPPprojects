/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:32:11 by marschul          #+#    #+#             */
/*   Updated: 2024/02/22 19:17:28 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

# include "ICharacter.hpp"
# include "AMateria.hpp"

# include <string>

class Character : public ICharacter {
	private:
		std::string const	_name;
		AMateria			*_materias[4];
		int					_nr_used;
		AMateria			**_trash;
		int					_nrTrash;
		void				empty(int idx);

	public:
		Character();
		~Character();
		Character(std::string name);
    	Character(const Character& other);
    	Character& 			operator=(const Character& other);
		std::string const & getName() const; 
		void 				equip(AMateria* m);
		void 				unequip(int idx);
		void 				use(int idx, ICharacter& target);
};

#endif
