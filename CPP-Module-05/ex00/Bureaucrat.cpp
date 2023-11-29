/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:34:16 by bmengouc          #+#    #+#             */
/*   Updated: 2023/11/06 21:34:26 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("default"), grade(1)
{
    std::cout << "Bureaucrat Default Constructor Called\n";
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat Destructor Called\n";
}

Bureaucrat::Bureaucrat(std::string nm, int gd) : name(nm)
{
	std::cout << "Bureaucrat Constructor with parameters Called\n";
	try
	{
		if (gd > 150)
			throw GradeTooLowException("Grade is too low");
		else if (gd < 1)
			throw GradeTooHighException("Grade is too high");
		this->grade = gd;
	}
	catch (const Bureaucrat::GradeTooLowException& e) 
	{
        std::cout << "Caught a GradeTooLowException: " << e._message << std::endl;
		throw;
    }
	catch (const Bureaucrat::GradeTooHighException& e)
	{
        std::cout << "Caught a GradeTooHighException: " << e._message << std::endl;
		throw;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name)
{
	std::cout << "Bureaucrat Copy Constructor Called\n";
	this->grade = copy.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat Assignment operator Called\n";
	if (this != &other)
		this->grade = other.grade;
	return (*this);
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

std::string Bureaucrat::getName() const
{
	return this->name;
}

void	Bureaucrat::incrementGrade()
{
	try
	{
		if (grade - 1 < 1)
			throw GradeTooHighException("Grade is too high");
		this->grade -= 1;
	}
	catch (const Bureaucrat::GradeTooHighException& e) 
	{
        std::cout << "Caught a GradeTooHighException: " << e._message << std::endl;
		throw;
	}
}

void	Bureaucrat::decrementGrade()
{
	try
	{
		if (this->grade + 1 > 150)
			throw GradeTooLowException("Grade is too low");
		this->grade += 1;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
        std::cout << "Caught a GradeTooLowException: " << e._message << std::endl;
		throw;
	}
}

// Implement the operator<< function
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << "*****> Bureaucrat Details <*****" << std::endl;
    os << "---> Name: " << bureaucrat.getName() << std::endl;
	os << "---> Grade: " << bureaucrat.getGrade() << std::endl;
    return os;
}
