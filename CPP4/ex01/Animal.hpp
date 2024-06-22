/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:48:21 by marschul          #+#    #+#             */
/*   Updated: 2024/02/22 18:51:18 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include <string>

class Animal {
protected:
    std::string type;

public:
    Animal();
    Animal(const Animal& other);
    virtual ~Animal();
    Animal& 			operator=(const Animal& other);
	std::string			getType(void) const;
    virtual void 		makeSound() const;
	virtual void		setThought(std::string thought, int i) = 0;
	virtual std::string	getThought(int i) const = 0;
};

#endif
