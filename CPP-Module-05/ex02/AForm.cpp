/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:07:30 by bmengouc          #+#    #+#             */
/*   Updated: 2023/11/22 22:07:31 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

AForm::AForm() : name("Defualt"), req_grade_to_sign(50),
				req_grade_to_exec(50)
				 
{
	std::cout << "Form Default Constructor Called" << std::endl;
	this->is_signed = false;
}

AForm::AForm(std::string nm, int rgts, int rgte) : name(nm), req_grade_to_sign(rgts),
				req_grade_to_exec(rgte)
				 
{
	std::cout << "Form Constructor with parameters Called" << std::endl;
	this->is_signed = false;
}

AForm::~AForm()
{
	std::cout << "Form Destructor Called" << std::endl;
}

AForm::AForm(const AForm &copy) : name(copy.name), 
	req_grade_to_sign(copy.req_grade_to_sign), 
	req_grade_to_exec(copy.req_grade_to_exec)
{
	std::cout << "Form Copy Constructor Called\n";
}

AForm& AForm::operator=(const AForm &other)
{
	std::cout << "Form Assignment operator Called\n";
	if (this != &other)
		*this = other;
	return (*this);
}

// Getters
std::string	AForm::getName() const
{
	return (this->name);
}

bool	AForm::isSigned() const
{
	return (this->is_signed);
}

int	AForm::reqGradeToSign() const
{
	return (this->req_grade_to_sign);	
}

int AForm::reqGradeToExec() const
{
	return (this->req_grade_to_exec);
}

// Setters
void	AForm::setSigned(bool bit)
{
	this->is_signed = bit;
}

// Implement the operator<< function
std::ostream& operator<<(std::ostream& os, AForm& form)
{
	os << "*****> Form Details <*****" << std::endl;
	os << "---> Name: " << form.getName() << std::endl;
	os << "---> Is Signed: " << (form.isSigned() ? "Yes" : "No") << std::endl;
	os << "---> Required Grade To Sign: " << form.reqGradeToSign() << std::endl;
	os << "---> Required Grade To Execute: " << form.reqGradeToExec() << std::endl;
    return os;
}
