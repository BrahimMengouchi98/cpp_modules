/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:12:56 by bmengouc          #+#    #+#             */
/*   Updated: 2023/11/22 22:12:57 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137)
{
	std::cout << "ShrubberyCreationForm Default Constructor Called\n";
	this->target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string trgt) 
	: AForm("Shrubbery", 145, 137)
{
	std::cout << "ShrubberyCreationForm Constructor with parameter Called\n";
	this->target = trgt;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor Called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
{
	std::cout << "ShrubberyCreationForm Copy Constructor Called\n";
	this->target = copy.target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "ShrubberyCreationForm Assignment operator Called\n";
	if (this != &other)
		*this = other;
	return (*this);
}

void	ShrubberyCreationForm::beSigned(Bureaucrat& bureaucrat)
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

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (executor.getGrade() <= this->reqGradeToExec())
		{
			// Open the file for writing
			std::ofstream outFile(this->target + "_shrubbery");
			if (outFile.is_open())
			{
				// Write the ASCII tree inside the file
				for (int i = 0; i < 3; i++)
				{
					outFile <<    
					"		      X" << std::endl <<
					"		     EdF" << std::endl <<
					"		    WEEdF" << std::endl <<
					"		  XWEZZddF" << std::endl <<
					"		 XEWE-.EddF" << std::endl <<
					"    	IMb>>.R.RddF" << std::endl <<
					"  	   @$$$.eqeiBzddF" << std::endl <<
					"    d$1i9$b<|82ez$dddF" << std::endl <<
					"   @d\\9$8$@$b$@de/ddddF" << std::endl <<
					" .d$@$$\\$$$$$@b.$wsddddF" << std::endl <<
					".dM$E$N$G$\\O$U.dM$E$N$G$@" << std::endl <<
					"           |@@@|" << std::endl <<
					"           |@@@|" << std::endl <<
					"           |@@@|" << std::endl <<
					std::endl;
				}
				outFile.close();
			}
			else
				std::cerr << "Error: Unable to open file for writing.\n";
		}
		else 
			throw ShrubberyCreationForm::GradeTooLowException("grade too low");
	}
	catch (const ShrubberyCreationForm::GradeTooLowException& e) 
	{
		std::cout << "Caught a GradeTooLowException: " << e._message << std::endl;
		throw;
	}	
}
