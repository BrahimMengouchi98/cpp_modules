# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("presidential pardon", 25, 5)
{
	this->target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string trgt) 
	: AForm("presidential pardon", 25, 5)
{
	this->target = trgt;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
{
	this->target = copy.target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
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