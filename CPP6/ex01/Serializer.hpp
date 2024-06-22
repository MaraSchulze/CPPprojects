/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:59:49 by marschul          #+#    #+#             */
/*   Updated: 2024/03/12 18:42:17 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

typedef struct s_data {
	int	a;
	int	b;
}	Data;

typedef unsigned long	uintptr_t;

class  Serializer {
	private:
		Serializer();
		Serializer(const Serializer& other);
	
	public:
		~Serializer();
		Serializer&	operator=(const Serializer& other);
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
