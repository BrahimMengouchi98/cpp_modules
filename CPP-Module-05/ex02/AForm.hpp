/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:07:47 by bmengouc          #+#    #+#             */
/*   Updated: 2023/11/22 22:07:48 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool 	  			is_signed;
		const int 			req_grade_to_sign;
		const int 			req_grade_to_exec;
	public:

		// Constructors
		AForm();
		AForm(std::string nm, int rgts, int rgte);
		~AForm();

		// copy constuctor
		AForm(const AForm &copy);

		// Assignment operator
		AForm& operator=(const AForm &other);

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

		// Getters
		std::string	getName() const;
		bool		isSigned() const;
		int			reqGradeToSign() const;
		int			reqGradeToExec() const;

		// Setters
		void		setSigned(bool bit);

		// members function
		virtual void	beSigned(Bureaucrat& bureuacrat) = 0;
		virtual	void	execute(Bureaucrat const & executor) const = 0;
};

// the operator<< function
std::ostream& operator<<(std::ostream& os, AForm& form);

#endif
