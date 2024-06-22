/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:34:23 by marschul          #+#    #+#             */
/*   Updated: 2024/03/19 12:15:40 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <iostream>

class  Span {
	private:
		std::vector<int>	_vec;
		int					_size;

	public:
		Span();
		Span(int n);
		Span(const Span& other);
		~Span();
		Span&	operator=(const Span& other);
		void	addNumber(int size);
		int		shortestSpan(void);
		int		longestSpan(void);

	public:
		template <typename Iterator>
		void addNumberRange(Iterator begin, Iterator end) {
			int rangeSize = end - begin;

			if (_vec.end() + _size < _vec.end() + rangeSize)
				throw Span::SizeException();
			for (; begin != end; begin++) {
				_vec.push_back(*begin);
			}
		}

	public:
		class SizeException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class NoSpanException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif
