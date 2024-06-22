/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:14:01 by marschul          #+#    #+#             */
/*   Updated: 2024/04/11 17:46:53 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <list>
# include <map>

class  PMergeMe {
	private:
		std::vector<int>	_vector;
		std::list<int>		_list;
		void						divideV(std::vector<int>& original, std::vector<int>& winner, std::vector<int>& loser);
		void						createPositionMapV(std::multimap<int, int>& positions, std::vector<int>& winner, std::vector<int>& loser);
		void						updatePositionMapV(std::multimap<int, int>& positions, std::vector<int>& winner);
		std::vector<int>::iterator	binarySearchV(std::vector<int>::iterator left, std::vector<int>::iterator right, int number);
		void 						insertV(std::vector<int>& winner, std::vector<int>& loser, std::multimap<int, int>& positions);
		void						sortRecursivelyV(std::vector<int>& original);

		void						divideL(std::list<int>& original, std::list<int>& winner, std::list<int>& loser);
		void						createPositionMapL(std::multimap<int, int>& positions, std::list<int>& winner, std::list<int>& loser);
		void						updatePositionMapL(std::multimap<int, int>& positions, std::list<int>& winner);
		std::list<int>::iterator	binarySearchL(std::list<int>::iterator left, std::list<int>::iterator right, int number);
		void 						insertL(std::list<int>& winner, std::list<int>& loser, std::multimap<int, int>& positions);
		void						sortRecursivelyL(std::list<int>& original);
	public:
		PMergeMe();
		PMergeMe(const PMergeMe& other);
		~PMergeMe();
		PMergeMe&	operator=(const PMergeMe& other);
		bool		getList(int argc, char **argv);
		void		printList();
		void		sortVector();
		void		sortLinkedList();
};

#endif
