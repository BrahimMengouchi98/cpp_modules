/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:12:32 by bmengouc          #+#    #+#             */
/*   Updated: 2023/11/22 22:12:33 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
