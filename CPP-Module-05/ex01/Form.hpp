/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:10:27 by bmengouc          #+#    #+#             */
/*   Updated: 2023/11/09 23:10:29 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool 	  			is_signed;
		const int 			req_grade_to_sign;
		const int 			req_grade_to_exec;
	public:

		// Constructors
		Form();
		Form(std::string nm, int rgts, int rgte);
		~Form();

		// copy constuctor
		Form(const Form &copy);

		// Assignment operator
		Form& operator=(const Form &other);

		// GradeTooHighException
		class GradeTooHighException : public std::exception
		{
			public:
				std::string _message;
				GradeTooHighException(std::string message) : _message(message){}
				virtual ~GradeTooHighException() throw (){}
		};

		// GradeTooLowException
		class GradeTooLowException : public std::exception
		{
			public:
				std::string _message;
				GradeTooLowException(std::string message) : _message(message){}
				virtual ~GradeTooLowException() throw() {}
		};

		// Getter
		std::string	getName() const;
		bool		isSigned();
		int			reqGradeToSign() const;
		int			reqGradeToExec() const;

		// members function
		void	beSigned(Bureaucrat& bureuacrat);
};

// the operator<< function
std::ostream& operator<<(std::ostream& os, Form& form);

#endif
