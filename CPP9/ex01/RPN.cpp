/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:04:39 by marschul          #+#    #+#             */
/*   Updated: 2024/04/11 20:11:09 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

RPN::RPN() : _stack(std::stack<int>()), _error(0) {}

RPN::RPN(const RPN& other) : _stack(other._stack), _error(other._error) {}

RPN::~RPN() {}

RPN&	RPN::operator=(const RPN& other) {
	if (this != &other) {
		_error = other._error;
		_stack = other._stack;
	}
	return *this;
}

bool	RPN::isOperator(std::string op) {
	if (op.size() == 1 && (op[0] == '+' || op[0] == '-' || \
		op[0] == '*' || op[0] == '/'))
		return true;
	else
		return false;
}

bool	isInt(std::string& str) {
	long int	number;
	char		*end;

	number = strtol(str.c_str(), &end, 10);
	number++;
	if (*end == '\0')
		return true;
	else
		return false;
}

bool	isInRange(long int number) {
	if (number >= -2147483648 && number <= 2147483647)
		return true;
	else
		return false;
}

bool	RPN::readIn(char *expression) {
	std::istringstream	iss(expression);
	std::string			str;
	long int			number;

	while (iss >> str) {
		if (isOperator(str) == true) {
			_stack.push(str[0]);
			continue;
		}
		if (isInt(str) == true) {
			number = std::atoi(str.c_str());
			if (number <= 9 && number >= 0) {
				_stack.push(str[0]);
				continue;
			}
		}
		std::cout << "Error: Parsing" << std::endl;
		return false;
	}
	return true;
}

int	RPN::doOp() {
	char		token;
	int			left;
	int			right;
	long int 	result;

	if (_stack.size() == 0) {
		_error = 1;
		return 0;
	}
	token = _stack.top();
	_stack.pop();
	if (isOperator(std::string(1, token)) == false)
		return (long int) token - '0';
	right = doOp();
	left = doOp();
	switch (token) {
		case '+':
			result = left + right;
			break;
		case '-':
			result = left - right;
			break;
		case '*':
			result = left * right;
			break;
		case '/':
			if (right == 0) {
				_error = 3;
				return 0;
			}
			result = left / right;
			break;
	}
	if (isInRange(result) == false) {
		_error = 2;
		return 0;
	}
	return result;
}

void	RPN::calculate() {
	int	result;
	
	result = doOp();
	if (_error == 2)
		std::cout << "Error: Overflow" << std::endl;
	else {
		if (_error == 1 || _stack.size() != 0)
			std::cout << "Error: Wrong expression" << std::endl;
		else {
			if (_error == 3)
				std::cout << "Error: Division by zero" << std::endl;
			else
				std::cout << result << std::endl;
		}
	}
}
