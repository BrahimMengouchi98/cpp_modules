# ifndef PRESIDENTIALPARDONFORM_HPP

# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string target;
		
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string trgt);
		~PresidentialPardonForm();

		// copy constuctor
		PresidentialPardonForm(const PresidentialPardonForm &copy);

		// Assignment operator
		PresidentialPardonForm& operator=(const PresidentialPardonForm &other);

		void beSigned(Bureaucrat& bureaucrat);
		void execute(Bureaucrat const & executor) const;
};

#endif