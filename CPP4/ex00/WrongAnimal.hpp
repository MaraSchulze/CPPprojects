/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:42:27 by marschul          #+#    #+#             */
/*   Updated: 2024/02/22 16:15:34 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_H
# define WRONG_ANIMAL_H

# include <string>

class WrongAnimal {
protected:
    std::string _type;

public:
    WrongAnimal();
    WrongAnimal(std::string type);
    WrongAnimal(const WrongAnimal& other);
    virtual ~WrongAnimal();
    WrongAnimal&	operator=(const WrongAnimal& other);
    void		 	makeSound() const;
	std::string		getType(void) const;
};

#endif