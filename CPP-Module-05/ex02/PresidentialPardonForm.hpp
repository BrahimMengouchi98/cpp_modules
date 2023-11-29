/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:11:26 by bmengouc          #+#    #+#             */
/*   Updated: 2023/11/22 22:11:27 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
