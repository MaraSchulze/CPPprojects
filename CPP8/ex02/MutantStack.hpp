/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:16:12 by marschul          #+#    #+#             */
/*   Updated: 2024/03/19 12:39:35 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <vector>
# include <iterator>
# include <cstddef>


template<typename T>
class MutantStack : public std::stack<T> {
	private:
		std::vector<T>	_mirror;

	public:
		class iterator : public std::iterator<std::random_access_iterator_tag, T> {
			private:
				T*	_ptr;

			public:
				typedef T value_type;
				typedef ptrdiff_t difference_type;
				typedef T* pointer;
				typedef T& reference;
				typedef std::random_access_iterator_tag iterator_category;

				iterator();
				iterator(T* ptr);
				iterator(const iterator& other);
				iterator& operator=(const iterator& other);
				~iterator();
				bool operator==(const iterator& other) const;
				bool operator!=(const iterator& other) const;
				reference operator*() const;
				pointer operator->() const;
				iterator& operator++();
				iterator operator++(int);
				iterator& operator--();
				iterator operator--(int);
				iterator operator+(difference_type n) const;
				iterator& operator+=(difference_type n);
				iterator operator-(difference_type n) const;
				iterator& operator-=(difference_type n);
				difference_type operator-(const iterator& other) const;
				bool operator<(const iterator& other) const;
				bool operator>(const iterator& other) const;
				bool operator<=(const iterator& other) const;
				bool operator>=(const iterator& other) const;
				reference operator[](difference_type n) const;
    	};
		
	public:
		MutantStack();
		MutantStack(const MutantStack& other);
		~MutantStack();
		MutantStack&			operator=(const MutantStack& other);
		void 					push(const T& element);
		void 					pop();
		MutantStack::iterator	begin();
		MutantStack::iterator	end();
};

# include "MutantStack.tpp"

#endif
