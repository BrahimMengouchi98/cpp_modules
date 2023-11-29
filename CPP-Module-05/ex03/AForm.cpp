/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:10:00 by bmengouc          #+#    #+#             */
/*   Updated: 2023/11/23 17:10:01 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

AForm::AForm() : name("Defualt"), req_grade_to_sign(50),
				req_grade_to_exec(50)
				 
{
	this->is_signed = false;
}

AForm::AForm(std::string nm, int rgts, int rgte) : name(nm), req_grade_to_sign(rgts),
				req_grade_to_exec(rgte)
				 
{
	this->is_signed = false;
}

AForm::~AForm()
{

}

AForm::AForm(const AForm &copy) : name(copy.name), 
	req_grade_to_sign(copy.req_grade_to_sign), 
	req_grade_to_exec(copy.req_grade_to_exec)
{

}

AForm& AForm::operator=(const AForm &other)
{
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
	os << "---> Is Signed: " << (form.isSigned() ? "Yes" : "NO") << std::endl;
	os << "---> Required Grade To Sign: " << form.reqGradeToSign() << std::endl;
	os << "---> Required Grade To Execute: " << form.reqGradeToExec() << std::endl;
    return os;
}
