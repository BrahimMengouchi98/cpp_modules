# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy request", 72, 45)
{
	this->target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string trgt) 
	: AForm("robotomy request", 72, 45)
{
	this->target = trgt;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
{
	this->target = copy.target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
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