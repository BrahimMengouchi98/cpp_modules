# ifndef ROBOTOMYREQUESTFORM_HPP

# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string trgt);
		~RobotomyRequestForm();
		
		// copy constuctor
		RobotomyRequestForm(const RobotomyRequestForm &copy);

		// Assignment operator
		RobotomyRequestForm& operator=(const RobotomyRequestForm &other);

		void beSigned(Bureaucrat& bureaucrat);
		void execute(Bureaucrat const & executor) const;
};

#endif