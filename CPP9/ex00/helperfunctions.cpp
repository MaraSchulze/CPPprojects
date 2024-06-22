/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helperfunctions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:56:59 by marschul          #+#    #+#             */
/*   Updated: 2024/03/27 21:41:44 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <iostream>
#include <cctype>

bool	handleError(t_order *order, std::string message, std::string line) {
	order->isError = true;
	order->errorMessage = message + " => " + line;
	return false;
}

bool	isAllDigits(std::string str) {
	for (size_t i = 0; i < str.size(); i++) {
		if (isdigit(str[i]) == false)
			return false;
	}
	return true;
}

bool	isFloat(std::string str) {
	size_t	pos1, pos2;
	
	pos1 = str.find(".");
	if (pos1 != std::string::npos) {
		pos2 = str.find(".", pos1 + 1);
		if (pos2 != std::string::npos)
			return false;
	}
	for (size_t i = 0; i < str.size(); i++) {
		if (isdigit(str[i]) == false && str[i] != '.')
			return false;
	}
	return true;	
}

bool	checkFormatErrors(std::string line, t_order *order) {
	// check if " | " is there
	std::size_t	position;

	position = line.find(" | ");
	if (position == std::string::npos) 
		return handleError(order, "Error: Wrong format", line);

	// check if date is in right format
	std::string	date = line.substr(0, position);

	if (date[4] != '-' || date[7] != '-' || date.size() != 10)
		return handleError(order, "Error: Bad date format", line);

	// check if date is valid date
	int			month, day;
	std::string yearStr, monthStr, dayStr;
	int			nrDays[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};

	yearStr = line.substr(0, 4);
	monthStr = line.substr(5, 2);
	dayStr = line.substr(8, 2);
	if (isAllDigits(yearStr) == false || isAllDigits(monthStr) == false || isAllDigits(dayStr) == false)
		return handleError(order, "Error: Bad date", line);
	month = atoi(monthStr.c_str());
	day = atoi(dayStr.c_str());
	if (month < 1 || month > 12 || day < 1 || day > nrDays[month - 1])
		return handleError(order, "Error: Bad date", line);

	// check for valid order
	std::string	amountStr;

	amountStr = line.substr(position + 3);
	if (isFloat(amountStr) == false)
		return handleError(order, "Error: Order is not a number", line);

	// check for range
	float		amount;
	
	amount = atof(amountStr.c_str());
	if (amount < 0.0 || amount > 1000.0)
		return handleError(order, "Error: order volume not between 0 and 1000", line);

	return true;
}
