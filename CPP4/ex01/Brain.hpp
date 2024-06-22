/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:44:12 by marschul          #+#    #+#             */
/*   Updated: 2024/02/22 18:51:58 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class	Brain {
	private:
		std::string	ideas[100];

	public:
		Brain();
		Brain(const Brain& other);
		virtual ~Brain();
		Brain& 		operator=(const Brain& other);
		std::string	getIdea(int i) const;
		void		setIdea(std::string str, int i);
		void		copyIdeas(std::string *newIdeas);
};

#endif
