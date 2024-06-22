/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:54:59 by marschul          #+#    #+#             */
/*   Updated: 2024/03/07 15:30:35 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>

class Bureaucrat;

class AForm {
	private:
		const std::string	name;
		bool 				isSigned;
		const int			requiredGradeToSign;
		const int			requiredGradeToExecute;
		std::string			target;

	public:
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class NotSignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	public:
		AForm();
		AForm(const std::string &name, bool isSigned, int requiredGradeToSign, 
			int requiredGradeToExecute, const std::string& target);
		AForm(const AForm& other);
		~AForm();
		AForm& 				operator=(const AForm& other);
		const std::string& 	getName() const;
		bool			 	getIsSigned() const;
		const std::string& 	getTarget() const;
		int					getRequiredGradeToSign() const;
		int					getRequiredGradeToExecute() const;
		bool				beSigned(Bureaucrat& bureaucrat);
		void				execute(Bureaucrat const & executor) const;
		virtual void		execute_action(void) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm& form);

#endif
