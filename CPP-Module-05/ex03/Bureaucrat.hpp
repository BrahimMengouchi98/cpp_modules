/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:34:16 by bmengouc          #+#    #+#             */
/*   Updated: 2023/11/06 21:34:26 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"
class AForm;

class Bureaucrat
{
	private:
		const		std::string name;
		int			grade;
	public:

		Bureaucrat();
		Bureaucrat(std::string nm, int gd);
		~Bureaucrat();

		// copy constuctor
		Bureaucrat(const Bureaucrat &copy);

		// Assignment operator
		Bureaucrat& operator=(const Bureaucrat &other);

		// Getter
		std::string	getName() const;
		int			getGrade() const;
		void		incrementGrade();
		void		decrementGrade();

		// Members function
		void	signForm(AForm& form);
		void	executeForm(AForm const & form);

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
};

// the operator<< function
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif