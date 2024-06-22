/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:13:15 by marschul          #+#    #+#             */
/*   Updated: 2024/01/19 20:57:05 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

std::string	replace(std::string inbuffer, char *s1, char *s2);

int	main(int argc, char **argv)
{
	std::stringstream	buffer;
	std::string 		inbuffer;
	std::string 		outbuffer;
	std::string 		outfile(argv[1]);

	if (argc != 4)
	{
		std::cout << "Wrong parameters" << std::endl;
		return (1);
	}
	
	std::ifstream	inputFile(argv[1]);
	if (! inputFile.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		return (1);
	}
	buffer << inputFile.rdbuf();
	inputFile.close();
	inbuffer = buffer.str();

	outbuffer = replace(inbuffer, argv[2], argv[3]);

	outfile += ".replace";
	std::ofstream	outputFile(outfile);
	if (! outputFile.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		return (1);
	}
	outputFile << outbuffer;
	outputFile.close();
	return (0);
}
