/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:13:02 by marschul          #+#    #+#             */
/*   Updated: 2024/03/19 17:21:11 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <map>
# include <deque>

typedef struct s_order {
	std::string	date;
	float		nrOrders;
	bool		isError;
	std::string	errorMessage;
}	t_order;

class  BitcoinExchange {
	private:
		std::map<std::string, double>	_prices;
		std::deque<t_order*>			_orders;
		void	copyDeque(std::deque<t_order*>& dest, const std::deque<t_order*>& src);
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		~BitcoinExchange();
		BitcoinExchange&	operator=(const BitcoinExchange& other);
		bool				readInPrices();
		bool				readInOrders(const char *fileName);
		void				trade() const;
};

bool	checkFormatErrors(std::string line, t_order *order);

#endif
