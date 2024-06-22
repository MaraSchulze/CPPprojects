/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 06:36:19 by marschul          #+#    #+#             */
/*   Updated: 2024/01/17 19:01:43 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <string>

class Zombie {
private:
    std::string name;

public:
    Zombie(std::string newName);
    void	announce(void);
    ~Zombie();
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
