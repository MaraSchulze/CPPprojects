/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:58:25 by marschul          #+#    #+#             */
/*   Updated: 2024/02/18 19:27:01 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
private:
	Brain	*brain;
public:
    Cat();
    ~Cat();
    Cat(const Cat& other);
    Cat& 		operator=(const Cat& other);
    void 		makeSound(void) const;
	void		setThought(std::string thought, int i);
	std::string	getThought(int i) const;
};

#endif
