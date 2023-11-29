/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:10:56 by bmengouc          #+#    #+#             */
/*   Updated: 2023/11/23 17:10:57 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef INTERN_HPP

#define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		/* data */
	public:
		Intern(/* args */);
		~Intern();
	
	// copy constuctor
	Intern(const Intern &copy);

	// Assignment operator
	Intern& operator=(const Intern &other);

	// Members Function
	AForm *makeForm(std::string name, std::string target);

	// GradeTooHighException
	class FormException : public std::exception
	{
		public:
			std::string _message;
			FormException(const char* message) : _message(message){}
			virtual ~FormException() throw (){}
	};

};

# endif
