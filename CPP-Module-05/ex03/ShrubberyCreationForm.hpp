# ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
#include  <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string trgt);
		~ShrubberyCreationForm();

		// copy constuctor
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);

		// Assignment operator
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);

		void beSigned(Bureaucrat& bureaucrat);
		void execute(Bureaucrat const & executor) const;
};

#endif