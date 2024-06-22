/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:55:38 by marschul          #+#    #+#             */
/*   Updated: 2024/02/18 19:27:25 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
private:
	Brain	*brain;
public:
    Dog();
    ~Dog();
    Dog(const Dog& other);
    Dog& 	operator=(const Dog& other);
    void 		makeSound() const;
	void		setThought(std::string thought, int i);
	std::string	getThought(int i) const;
};

#endif 