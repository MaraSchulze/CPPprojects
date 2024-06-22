/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:54:59 by marschul          #+#    #+#             */
/*   Updated: 2024/03/06 12:01:53 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>

class Bureaucrat;

class Form {
	private:
		const std::string	name;
		bool 				isSigned;
		const int			requiredGradeToSign;
		const int			requiredGradeToExecute;

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
		Form();
		Form(const std::string& name, int requiredGradeToSign, int requiredGradeToExecute);
		Form(const Form& other);
		~Form();
		Form& 				operator=(const Form& other);
		const std::string& 	getName() const;
		bool			 	getIsSigned() const;
		int					getRequiredGradeToSign() const;
		int					getRequiredGradeToExecute() const;
		void				beSigned(Bureaucrat& bureaucrat);
};

std::ostream&	operator<<(std::ostream& out, const Form& form);

#endif
