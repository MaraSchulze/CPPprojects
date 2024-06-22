/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:07:45 by marschul          #+#    #+#             */
/*   Updated: 2024/04/11 18:38:08 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"
#include <iostream>
#include <ctime>

int main(int argc, char **argv) {
	PMergeMe	pMergeMe = PMergeMe();
	clock_t start1, start2, stop1, stop2;

	// get list
	if (pMergeMe.getList(argc, argv) == false)
		return 1;

	// print list
	std::cout << "Before:" << std::endl;;
	pMergeMe.printList();
	
	// start timer, sort vector and stop timer
	start1 = clock();
	pMergeMe.sortVector();
	stop1 = clock();

	// start timer, sort list and stop timer
	start2 = clock();
	pMergeMe.sortLinkedList();
	stop2 = clock();

	// print sorted list 1
	std::cout << "After:" << std::endl;
	pMergeMe.printList();

	// print stats list 1
	std::cout << "Sorting time with vector:	" << (double)(stop1 - start1) / CLOCKS_PER_SEC << std::endl;

	// print stats list 2
	std::cout << "Sorting time with list:	" << (double)(stop2 - start2) / CLOCKS_PER_SEC << std::endl;
}
