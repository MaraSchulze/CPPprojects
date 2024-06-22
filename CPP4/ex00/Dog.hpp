/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:55:38 by marschul          #+#    #+#             */
/*   Updated: 2024/02/13 14:28:43 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"

class Dog : public Animal {
public:
    Dog();
    ~Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    void makeSound() const;
};

#endif 