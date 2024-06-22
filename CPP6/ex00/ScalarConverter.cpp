/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:45:53 by marschul          #+#    #+#             */
/*   Updated: 2024/03/11 21:24:38 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream>
#include <iomanip>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
		(void) other;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void) other;
    return *this;
}

void	display(char c, int i, float f, double d) {
	std::string	char_str, int_str;

	// set precision
	std::cout << std::setprecision(15);

	// display char
	if (d - i != 0.0 || i < 0 || i > 255)
		char_str = "impossible";
	else {
		if (i < 32 || i > 127)
			char_str = "Non displayable";
		else
			char_str = std::string(1, c);
	}
	std::cout << "char: " << char_str << std::endl;

	// display int
	if (d - i == 0.0) {
		std::stringstream ss;
		ss << i;
		int_str = ss.str();
	} else {
		int_str = "impossible";
	}
	std::cout << "int: " << int_str << std::endl;

	//display float
	if (f - i == 0.0f)
		std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;

	//display double
	if (d - i == 0.0)
		std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}

bool	ScalarConverter::convert_char(char *value) {
	char		c;

	std::string	s;

	// test if it is a char
	if (strlen(value) == 1 && (value[0] < '0' || value[0] > '9'))
		c = value[0];
	else
		return false;

	display(static_cast<char>(c), static_cast<int>(c), static_cast<float>(c), static_cast<double>(c));
	
	return true;
}

bool	ScalarConverter::convert_int(char *value) {
	int 		i;
	std::string	s;

	// test if it is an int
	if (! ((value[0] == '-' && strlen(value) > 1) || (value[0] >= '0' && value[0] <= '9')))
		return false;
	for (size_t j = 1; j < strlen(value); j++) {
		if (value[j] < '0' || value[j] > '9')
			return false;
	}

	// convert to int
    std::istringstream iss(value);
    if (! (iss >> i))
		return false;

	display(static_cast<char>(i), static_cast<int>(i), static_cast<float>(i), static_cast<double>(i));

	return true;
}

bool	is_float(char *value) {
	size_t	i;

	if (strlen(value) < 4)
		return false;
	if (value[strlen(value) - 1] != 'f')
		return false;
	if (strcmp("-inff", value) == 0 || strcmp("+inff", value) == 0 || strcmp("nanf", value) == 0)
		return true;
	if (std::string(value).find('.') == std::string::npos)
		return false;
	if (std::string(value).find('.', std::string(value).find('.') + 1) != std::string::npos)
		return false;
	if (value[0] == '-')
		i = 1;
	else
		i = 0;
	for (; i < strlen(value) - 2; i++) {
		if ((value[i] < '0' || value[i] > '9') && value[i] != '.')
			return false;
	}
	return true;
}

bool	ScalarConverter::convert_float(char *value) {
	float 		f;
	std::string	str_char, str_int, str_float;

	// if it is a float
	if (! is_float(value))
		return false;

	// convert
	if (strcmp("+inff", value) == 0)
		f = std::numeric_limits<float>::infinity();
 	else {
		if (strcmp("-inff", value) == 0)
			f = -std::numeric_limits<float>::infinity();
		else {
			if (strcmp("nan", value) == 0)
				f = std::numeric_limits<float>::quiet_NaN();
			else {
				value[strlen(value) - 1] = '\0';
				std::istringstream iss(value);
				if (! (iss >> f))
					return false;
			}
		}
	}

	display(static_cast<char>(f), static_cast<int>(f), static_cast<float>(f), static_cast<double>(f));

	return true;
}

bool	is_double(char *value) {
	size_t	i;

	if (strlen(value) < 3)
		return false;
	if (strcmp("-inf", value) == 0 || strcmp("+inf", value) == 0 || strcmp("nan", value) == 0)
		return true;
	if (std::string(value).find('.') == std::string::npos)
		return false;
	if (std::string(value).find('.', std::string(value).find('.') + 1) != std::string::npos)
		return false;
	if (value[0] == '-')
		i = 1;
	else
		i = 0;
	for (; i < strlen(value) - 1; i++) {
		if ((value[i] < '0' || value[i] > '9') && value[i] != '.')
			return false;
	}
	return true;
}

bool	ScalarConverter::convert_double(char *value) {
	double 		d;
	std::string	str_char, str_int, str_float;

	// if it is a double
	if (! is_double(value))
		return false;

	// convert
	if (strcmp("+inf", value) == 0)
		d = std::numeric_limits<float>::infinity();
 	else {
		if (strcmp("-inf", value) == 0)
			d = -std::numeric_limits<float>::infinity();
		else {
			if (strcmp("nan", value) == 0)
				d = std::numeric_limits<double>::quiet_NaN();
			else {
				std::istringstream iss(value);
				if (! (iss >> d))
					return false;
			}
		}
	}

	display(static_cast<char>(d), static_cast<int>(d), static_cast<float>(d), static_cast<double>(d));

	return true;
}

void	ScalarConverter::convert(char *str) {

	if ((convert_char(str) ||
		convert_int(str) ||
		convert_float(str) ||
		convert_double(str)) == false)
		std::cout << "char: impossible" << std::endl
			<< "int: impossible" << std::endl 
			<< "float: impossible" << std::endl
			<< "double: impossible" << std::endl;	
}
