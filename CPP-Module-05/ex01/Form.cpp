/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:11:03 by bmengouc          #+#    #+#             */
/*   Updated: 2023/11/09 23:11:04 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

Form::Form() : name("Defualt"), req_grade_to_sign(50),
				req_grade_to_exec(50)
				 
{
	std::cout << "Form Default Constructor Called" << std::endl;
	this->is_signed = false;
}

Form::Form(std::string nm, int rgts, int rgte) : name(nm), req_grade_to_sign(rgts),
				req_grade_to_exec(rgte)
				 
{
	std::cout << "Form Constructor with parameters Called" << std::endl;
	this->is_signed = false;
	try
	{
		if (rgts > 150)
			throw GradeTooLowException("Required grade to sign is too low");
		else if (rgts < 1)
			throw GradeTooHighException("Required grade to sign is too high");
		if (rgte > 150)
			throw GradeTooLowException("Required grade to execute is too low");
		else if (rgte < 1)
			throw GradeTooHighException("Required grade to exectue is too high");
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

Form::~Form()
{
	std::cout << "Form Destructor Called" << std::endl;
}

Form::Form(const Form &copy) : name(copy.name), 
	req_grade_to_sign(copy.req_grade_to_sign), 
	req_grade_to_exec(copy.req_grade_to_exec)
{
	std::cout << "Form Copy Constructor Called\n";
}

Form& Form::operator=(const Form &other)
{
	std::cout << "Form Assignment operator Called\n";
	if (this != &other)
		*this = other;
	return (*this);
}

// Getters
std::string	Form::getName() const
{
	return (this->name);
}

bool	Form::isSigned()
{
	return (this->is_signed);
}

int	Form::reqGradeToSign() const
{
	return (this->req_grade_to_sign);	
}

int Form::reqGradeToExec() const
{
	return (this->req_grade_to_exec);
}

// Members Function
void	Form::beSigned(Bureaucrat& bureaucrat)
{
	this->is_signed = false;
	try
	{
		if (bureaucrat.getGrade() <= this->req_grade_to_sign)
			this->is_signed = true;
		else
			throw GradeTooLowException("Grade is too low comparing to the required one");
	}
	catch (const Form::GradeTooLowException& e) 
	{
        std::cout << "Caught a GradeTooLowException: " << e._message << std::endl;
		throw;
    }
}

// Implement the operator<< function
std::ostream& operator<<(std::ostream& os, Form& form)
{
	os << "*****> Form Details <*****" << std::endl;
	os << "---> Name: " << form.getName() << std::endl;
	os << "---> Is Signed: " << (form.isSigned() ? "Yes" : "No") << std::endl;
	os << "---> Required Grade To Sign: " << form.reqGradeToSign() << std::endl;
	os << "---> Required Grade To Execute: " << form.reqGradeToExec() << std::endl;
    return os;
}
