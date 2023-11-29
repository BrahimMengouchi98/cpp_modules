/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:36:07 by bmengouc          #+#    #+#             */
/*   Updated: 2023/11/06 21:36:09 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Intern.hpp"

int main()
{
	{
		//"shrubbery creation" /* rqgs: 145, rqge: 137 */
		//"robotomy request" /* rqs: 72, rqe: 45 */
		//"presidential pardon" /* rqs: 25, rqe: 5 */
		try
		{
			Bureaucrat bu("bureaucrat 1", 10);
			Intern i;
			AForm *a = i.makeForm("shrubbery creation", "Cristmas");
			AForm *b = i.makeForm(" request", "Bender");

			a->beSigned(bu);
			a->execute(bu);
			bu.signForm(*a);
			bu.executeForm(*a);
			
			b->beSigned(bu);
			b->execute(bu);
			bu.signForm(*b);
			bu.executeForm(*b);
			
			delete a;
			delete b;
		}
		catch(const std::exception& e)
		{
			std::cout << "Something goes wrong !!";
		}
	}
	return (0);
}