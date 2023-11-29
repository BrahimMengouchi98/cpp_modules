/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:10:59 by bmengouc          #+#    #+#             */
/*   Updated: 2023/11/22 22:11:00 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Shrubbery", 25, 5)
{
	std::cout << "PresidentialPardonForm Default Constructor Called\n";
	this->target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string trgt) 
	: AForm("Shrubbery", 25, 5)
{
	std::cout << "PresidentialPardonForm Constructor with parameters Called\n";
	this->target = trgt;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor Called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
{
	std::cout << "PresidentialPardonForm Copy Constructor Called\n";
	this->target = copy.target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << "PresidentialPardonForm Assignment operator Called\n";
	if (this != &other)
		*this = other;
	return (*this);
}

void	PresidentialPardonForm::beSigned(Bureaucrat& bureaucrat)
{
	this->setSigned(false);
	try
	{
		if (bureaucrat.getGrade() <= this->reqGradeToSign())
			this->setSigned(true);
		else
			throw GradeTooLowException("Grade is too low comparing to the required one");
	}
	catch (const AForm::GradeTooLowException& e) 
	{
        std::cout << "Caught a GradeTooLowException: " << e._message << std::endl;
		throw;
    }
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (executor.getGrade() <= this->reqGradeToExec())
		{
			// exectue action
			std::cout << "the " << this->target << " has been pardoned by ";
			std::cout << "Zaphod Beeblebrox." << std::endl;
		}
		else 
			throw PresidentialPardonForm::GradeTooLowException("the pardoned failed.");
	}
	catch (const PresidentialPardonForm::GradeTooLowException& e) 
	{
        std::cout << e._message << std::endl;
		throw;
    }
	
}
