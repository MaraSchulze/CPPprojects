/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:59:12 by marschul          #+#    #+#             */
/*   Updated: 2024/03/29 13:42:23 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>

class  RPN {
	private:
		std::stack<int>	_stack;
		int				_error;
		bool	isOperator(std::string op);
		int		doOp();
	public:
		RPN();
		RPN(const RPN& other);
		~RPN();
		RPN&		operator=(const RPN& other);
		bool		readIn(char *expression);
		void		calculate();
};

#endif
