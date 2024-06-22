/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:34:29 by marschul          #+#    #+#             */
/*   Updated: 2024/03/19 12:05:01 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main() {
	// test 1
	MutantStack<int> mstack;

	mstack.push(5); 
	mstack.push(17);
	std::cout << "top element is " << mstack.top() << std::endl; 
	mstack.pop();
	std::cout << "size is currently " << mstack.size() << std::endl;
	mstack.push(3); 
	mstack.push(5); 
	mstack.push(737); 
	//[...] mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin(); 
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack); 

	// test 2
	std::list<int>	l;
	l.push_back(5); 
	l.push_back(17);
	std::cout << "top element is " << l.back() << std::endl; 
	l.pop_back();
	std::cout << "size is currently " << l.size() << std::endl;
	l.push_back(3); 
	l.push_back(5); 
	l.push_back(737); 
	//[...] l.push_back(0);
	std::list<int>::iterator lit = l.begin(); 
	std::list<int>::iterator lite = l.end();
	++lit;
	--lit;
	while (lit != lite) {
		std::cout << *lit << std::endl;
		++lit;
	}
	std::list<int> s2(l);
	return 0;
}
