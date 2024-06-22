/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:48:21 by marschul          #+#    #+#             */
/*   Updated: 2024/02/18 19:20:29 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_H
# define AANIMAL_H

# include <string>

class AAnimal {
protected:
    std::string type;
   	AAnimal();
    AAnimal(const AAnimal& other);
public:
    virtual ~AAnimal();
    AAnimal& 			operator=(const AAnimal& other);
	std::string			getType(void) const;
    virtual void 		makeSound() const;
	virtual void		setThought(std::string thought, int i) = 0;
	virtual std::string	getThought(int i) const = 0;
};

#endif
