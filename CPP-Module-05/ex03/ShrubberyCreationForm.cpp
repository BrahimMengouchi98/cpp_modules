# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery creation", 145, 137)
{
	this->target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string trgt) 
	: AForm("shrubbery creation", 145, 137)
{
	this->target = trgt;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
{
	this->target = copy.target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
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
