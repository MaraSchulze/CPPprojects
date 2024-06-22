/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:16:49 by marschul          #+#    #+#             */
/*   Updated: 2024/04/11 19:26:16 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>

PMergeMe::PMergeMe() {}

PMergeMe::PMergeMe(const PMergeMe& other) : _vector(other._vector), _list(other._list) {}

PMergeMe::~PMergeMe() {}

PMergeMe&	PMergeMe::operator=(const PMergeMe& other) {
	if (this != &other) {
		_vector = other._vector;
		_list = other._list;
	}
	return *this;
}

bool	PMergeMe::getList(int argc, char **argv) {
	int							number;
	std::multimap<int, bool> 	doubles;

	for (int i = 1; i < argc; i++) {
		std::istringstream iss(argv[i]);
		if (!(iss >> number) || number <= 0 || iss.peek() != std::istringstream::traits_type::eof()) {
			std::cout << "Error" << std::endl;
			return false;
		}
		if (doubles.find(number) == doubles.end()) {
			_vector.push_back(number);
			_list.push_back(number);
			doubles.insert(std::make_pair(number, true));
		} else {
			std::cout << "Error" << std::endl;
			return false;
		}
	}
	return true;
}

void	PMergeMe::printList() {
	for (std::vector<int>::iterator	it = _vector.begin(); it < _vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (std::list<int>::iterator	it = _list.begin(); it != _list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

/*************************** Vector functions ***********************/

void	PMergeMe::divideV(std::vector<int>& original, std::vector<int>& winner, std::vector<int>& loser) {
	std::vector<int>::iterator it;

	for (it = original.begin(); it < original.end() - 1; it += 2) {
		if (*it < *(it + 1)) {
			winner.push_back(*it);
			loser.push_back((*(it + 1)));
		} else {
			winner.push_back((*(it + 1)));
			loser.push_back(*it);
		}
	}
	if (it == original.end() - 1)
		loser.push_back(*it);
}

void	PMergeMe::createPositionMapV(std::multimap<int, int>& positions, std::vector<int>& winner, std::vector<int>& loser) {
	size_t	i;

	for (i = 0; i < winner.size(); i++) {
		positions.insert(std::make_pair(loser[i], winner[i]));
		positions.insert(std::make_pair(winner[i], -1));
	}
	if (i != loser.size())
		positions.insert(std::make_pair(loser[i], 0));
}

void	PMergeMe::updatePositionMapV(std::multimap<int, int>& positions, std::vector<int>& winner) {
	int	number;
	
	for (size_t i = 0; i < winner.size(); i++) {
		number = winner[i];
		positions.erase(positions.find(number));
		positions.insert(std::make_pair(number, i));
	}
}

std::vector<int>::iterator	PMergeMe::binarySearchV(std::vector<int>::iterator left, std::vector<int>::iterator right, int number) {
	std::vector<int>::iterator	middle;

	if (number < *left)
		return left;
	if (left + 1 == right)
		return right;
	middle = left + ((int) (right - left) / 2);
	if (*middle > number)
		right = middle;
	if (*middle < number)
		left = middle;
	return binarySearchV(left, right, number);
}

void 	PMergeMe::insertV(std::vector<int>& winner, std::vector<int>& loser, std::multimap<int, int>& positions) {
	std::vector<int>::iterator 	winnerIt;
	std::vector<int>::iterator 	start;
	int		position;
	std::multimap<int, int>::iterator		pairPartner;

	for (std::vector<int>::iterator loserIt = loser.begin(); loserIt != loser.end(); loserIt++) {
		pairPartner = positions.find(*loserIt);
		if (pairPartner->second == 0)
			position = 0;
		else
			position = (positions.find(pairPartner->second))->second;
		start = winner.begin() + position;
		winnerIt = binarySearchV(start, winner.end(), *loserIt);
		winner.insert(winnerIt, *loserIt);
	}
}

void	PMergeMe::sortRecursivelyV(std::vector<int>& original) {
	std::vector<int>		winner = std::vector<int>();
	std::vector<int>		loser = std::vector<int>();
	std::multimap<int, int>	positions;

	// base case
	if (original.size() <= 1)
		return;

	// divide into winner and loser
	divideV(original, winner, loser);

	// create map of number -> position
	createPositionMapV(positions, winner, loser);

	// recursion over winner
	sortRecursivelyV(winner);

	// update map
	updatePositionMapV(positions, winner);

	// insert losers into winners
	insertV(winner, loser, positions);
	
	original = winner;
}

void	PMergeMe::sortVector() {
	sortRecursivelyV(_vector);
}

/******************************** List methods ***************************************/

void	PMergeMe::divideL(std::list<int>& original, std::list<int>& winner, std::list<int>& loser) {
	std::list<int>::iterator 	it;
	size_t						i;
	int							firstNumber;
	int							secondNumber;

	for (it = original.begin(), i = 0; i < original.size() - 1; i += 2) {
		firstNumber = *it;
		it++;
		secondNumber = *it;
		it++;
		if (firstNumber < secondNumber) {
			winner.push_back(firstNumber);
			loser.push_back(secondNumber);
		} else {
			winner.push_back(secondNumber);
			loser.push_back(firstNumber);
		}
	}
	if (i == original.size() - 1)
		loser.push_back(*it);
}

void	PMergeMe::createPositionMapL(std::multimap<int, int>& positions, std::list<int>& winner, std::list<int>& loser) {
	size_t						i;
	std::list<int>::iterator	winnerIt;
	std::list<int>::iterator	loserIt;

	winnerIt = winner.begin();
	loserIt = loser.begin();
	for (i = 0; i < winner.size(); i++) {
		positions.insert(std::make_pair(*loserIt, *winnerIt));
		positions.insert(std::make_pair(*winnerIt, -1));
		winnerIt++;
		loserIt++;
	}
	if (i != loser.size())
		positions.insert(std::make_pair(*loserIt, 0));
}

void	PMergeMe::updatePositionMapL(std::multimap<int, int>& positions, std::list<int>& winner) {
	int							number;
	std::list<int>::iterator	winnerIt;

	winnerIt = winner.begin();
	for (size_t i = 0; i < winner.size(); i++) {
		number = *winnerIt;
		positions.erase(positions.find(number));
		positions.insert(std::make_pair(number, i));
		winnerIt++;
	}
}

std::list<int>::iterator	PMergeMe::binarySearchL(std::list<int>::iterator left, std::list<int>::iterator right, int number) {
	std::list<int>::iterator	middle;
	std::list<int>::iterator	temp;
	int							i;

	if (number < *left)
		return left;
	temp = ++left;
	if (temp == right)
		return right;
	i = 0;
	for (temp = left; temp != right; temp++)
		i++;
	middle = left;
	for (int j = 0; j < ((int) (i / 2)); j++)
		middle++;
	if (*middle > number)
		right = middle;
	if (*middle < number)
		left = middle;
	return binarySearchL(left, right, number);
}

void 	PMergeMe::insertL(std::list<int>& winner, std::list<int>& loser, std::multimap<int, int>& positions) {
	std::list<int>::iterator 			winnerIt;
	std::list<int>::iterator 			start;
	int									position;
	std::multimap<int, int>::iterator	pairPartner;

	for (std::list<int>::iterator loserIt = loser.begin(); loserIt != loser.end(); loserIt++) {
		pairPartner = positions.find(*loserIt);
		if (pairPartner->second == 0)
			position = 0;
		else
			position = (positions.find(pairPartner->second))->second;
		start = winner.begin();
		for (int i = 0; i < position; i++)
			start++;
		winnerIt = binarySearchL(start, winner.end(), *loserIt);
		winner.insert(winnerIt, *loserIt);
	}
}

void	PMergeMe::sortRecursivelyL(std::list<int>& original) {
	std::list<int>		winner = std::list<int>();
	std::list<int>		loser = std::list<int>();
	std::multimap<int, int>	positions;

	// base case
	if (original.size() <= 1)
		return;

	// divide into winner and loser
	divideL(original, winner, loser);

	// create map of number -> position
	createPositionMapL(positions, winner, loser);

	// recursion over winner
	sortRecursivelyL(winner);

	// update map
	updatePositionMapL(positions, winner);

	// insert losers into winners
	insertL(winner, loser, positions);
	
	original = winner;
}

void	PMergeMe::sortLinkedList() {
	sortRecursivelyL(_list);
}
