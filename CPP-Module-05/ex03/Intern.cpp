/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:11:08 by bmengouc          #+#    #+#             */
/*   Updated: 2023/11/23 17:11:09 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

Intern::Intern()
{

}

Intern::~Intern()
{

}

Intern::Intern(const Intern &copy)
{
	*this = copy;
}

Intern& Intern::operator=(const Intern &other)
{
	if (this != &other)
		*this = other;
	return (*this);
}

// static functions for makeForm
AForm	*makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*makeRobot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	AForm *(*forms[])(std::string target) = {&makeShrubbery, &makeRobot, &makePresident};
	std::string strings[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	try
	{
		for (int i = 0; i < 3; i++)
		{
			if (strings[i] == name)
			{
				std::cout << "Intern creates " << name << std::endl;
				return (forms[i](target));
			}
		}
		throw FormException("Form doesn't exist !!");
	}
	catch(const Intern::FormException& e)
	{
		std::cout << e._message << std::endl;
		throw;
	}	
	return (NULL);
}
