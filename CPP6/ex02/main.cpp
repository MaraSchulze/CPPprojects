/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:29:29 by marschul          #+#    #+#             */
/*   Updated: 2024/03/12 18:33:54 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void) {
    std::srand(std::time(NULL));
	int	r = std::rand() % 3;

   	switch (r) {
		case 0 : 	return static_cast<Base*>(new A());
					break;
		case 1 : 	return static_cast<Base*>(new B());
					break;
		case 2 : 	return static_cast<Base*>(new C());
					break;
		default:	return NULL;
	}
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
    if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
    if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
}

void identify(Base& p) {
    try {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch (std::exception &e) {
        try {
            B &b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << "B" << std::endl;
        }
        catch (std::exception &e) {
            try {
                C &c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << "C" << std::endl;
            }
            catch (std::exception &e) {
                std::cout << "Not A, B, C class" << std::endl;
            }
        }
    }
}

int	main() {
	Base	*test;

	test = generate();
	identify(test);
	identify(*test);
}