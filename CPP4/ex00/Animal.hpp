/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:48:21 by marschul          #+#    #+#             */
/*   Updated: 2024/02/22 16:02:46 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include <string>

class Animal {
protected:
    std::string _type;

public:
    Animal();
    Animal(std::string type);
    Animal(const Animal& other);
    virtual ~Animal();
    Animal& 		operator=(const Animal& other);
    virtual void 	makeSound() const;
	std::string		getType(void) const;
};

#endif
