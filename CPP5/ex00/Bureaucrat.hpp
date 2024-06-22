/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:36:49 by marschul          #+#    #+#             */
/*   Updated: 2024/03/06 11:25:46 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class Bureaucrat {
	private:
		const std::string 	_name;
		int 				_grade;

	public:
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();
		Bureaucrat&			operator=(const Bureaucrat& other);
		const std::string&	getName() const;
		int 				getGrade() const;
		void 				incrementGrade();
		void 				decreaseGrade();
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
