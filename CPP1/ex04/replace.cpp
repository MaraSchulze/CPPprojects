/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:48:26 by marschul          #+#    #+#             */
/*   Updated: 2024/01/17 19:59:55 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

std::string	replace(std::string inbuffer, char *s1, char *s2)
{
	size_t		start = 0;
	size_t		find_position;
	std::string	outbuffer("");
	std::string	string1(s1);
	std::string	string2(s2);

	while ((find_position = inbuffer.find(string1, start)) != std::string::npos)
	{
		outbuffer += inbuffer.substr(start, find_position - start);
		outbuffer += string2;
		start = find_position + string1.length();
	}
	outbuffer += inbuffer.substr(start, inbuffer.length() - start);
	return outbuffer;
}