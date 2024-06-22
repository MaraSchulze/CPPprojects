/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:21:33 by marschul          #+#    #+#             */
/*   Updated: 2024/03/19 17:22:33 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>

BitcoinExchange::BitcoinExchange() : _prices(std::map<std::string, double>()), \
	_orders(std::deque<t_order*>()) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other): \
	_prices(other._prices), _orders(std::deque<t_order*>()) {}

BitcoinExchange::~BitcoinExchange() {
	for (std::deque<t_order*>::iterator it = _orders.begin(); it < _orders.end(); it++)
		delete *it;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		_prices = other._prices;
		_orders.clear();
		copyDeque(_orders, other._orders);
	}
	return *this;
}

bool	BitcoinExchange::readInPrices() {
    const char *DATANAME = "data.csv";
    std::string line;
	std::string date;
	std::string priceAsString;
	double		price;

    std::ifstream file(DATANAME);
    if (file.is_open() == false) {
        std::cerr << "Error: could not open file" << std::endl;
        return false;
    }
	if (std::getline(file, line).eof() == true)
		return false;
	_prices["0000-00-00"] = 0;
    while (std::getline(file, line).eof() == false) {
		date = line.substr(0, 10);
		priceAsString = line.substr(11);
		price = std::atof(priceAsString.c_str());
		_prices[date] = price;
    }
    file.close();
    return true;	
}

bool	BitcoinExchange::readInOrders(const char *fileName) {
    std::string line;
	t_order		*order;
	std::string	nrOrdersAsString;

    std::ifstream file(fileName);
    if (file.is_open() == false) {
        std::cerr << "Error: could not open file" << std::endl;
        return false;
    }
	if (std::getline(file, line).eof() == true || line != "date | value")
		return false;
    while (std::getline(file, line).eof() == false) {
		order = new t_order;
		order->isError = false;
		if (checkFormatErrors(line, order) == true) {
			order->date = line.substr(0, 10);
			nrOrdersAsString = line.substr(13);
			order->nrOrders = std::atof(nrOrdersAsString.c_str());
		}
		_orders.push_back(order);
    }
    file.close();
    return true;		
}

void	BitcoinExchange::trade() const {
	std::map<std::string, double>::const_iterator	itPrices;
	std::deque<t_order*>::const_iterator			itOrders;

	itOrders = _orders.begin();
	for (; itOrders != _orders.end(); itOrders++) {

		if ((*itOrders)->isError == false) {
			itPrices = _prices.end();
			itPrices--;
			while (itPrices->first > (*itOrders)->date)
				--itPrices;
			std::cout << (*itOrders)->date << " => " << (*itOrders)->nrOrders 
				<< " = " << (*itOrders)->nrOrders * itPrices->second << std::endl;
		}
		else
			std::cout << (*itOrders)->errorMessage << std::endl;
	}
}

void	BitcoinExchange::copyDeque(std::deque<t_order*>& dest, const std::deque<t_order*>& src) {
	t_order	*order;

	for (std::deque<t_order*>::const_iterator it = src.begin(); it < src.end(); it++) {
		order = new t_order;
		order->date = (*it)->date;
		order->nrOrders = (*it)->nrOrders;
		order->isError= (*it)->isError;
		order->errorMessage = (*it)->errorMessage;
		dest.push_back(order);
	}
}
