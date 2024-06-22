/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:58:25 by marschul          #+#    #+#             */
/*   Updated: 2024/02/13 15:15:19 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"

class Cat : public Animal {
public:
    Cat();
    ~Cat();
    Cat(const Cat& other);
    Cat& 		operator=(const Cat& other);
    void 		makeSound(void) const;
};

#endif
