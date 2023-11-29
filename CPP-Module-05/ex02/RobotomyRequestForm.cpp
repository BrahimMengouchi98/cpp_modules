/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:11:48 by bmengouc          #+#    #+#             */
/*   Updated: 2023/11/22 22:11:49 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Shrubbery", 72, 45)
{
	std::cout << "RobotomyRequestForm Default Constructor Called\n";
	this->target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string trgt) 
	: AForm("Shrubbery", 72, 45)
{
	std::cout << "RobotomyRequestForm Constructor with parameters Called\n";
	this->target = trgt;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor Called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
{
	std::cout << "RobotomyRequestForm Copy Constructor Called\n";
	this->target = copy.target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "RobotomyRequestForm Assignment operator Called\n";
	if (this != &other)
		*this = other;
	return (*this);
}

void	RobotomyRequestForm::beSigned(Bureaucrat& bureaucrat)
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

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (executor.getGrade() <= this->reqGradeToExec())
		{
			// exectue action
			std::cout << "the " << this->target << " has been robotomized ";
			std::cout << "successfully 50% of the time" << std::endl;
		}
		else 
			throw RobotomyRequestForm::GradeTooLowException("the robotomy failed.");
	}
	catch (const RobotomyRequestForm::GradeTooLowException& e) 
	{
        std::cout << e._message << std::endl;
		throw;
    }
	
}
