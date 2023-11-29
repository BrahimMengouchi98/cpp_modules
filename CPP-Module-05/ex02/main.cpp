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

int main()
{
	// Shrubbery
	{
		try
		{
			/* rqgs: 145, rqge: 137 */
			Bureaucrat b("bureaucrat 1", 146);
			ShrubberyCreationForm f1("home");
			
			f1.beSigned(b);
			f1.execute(b);
			
			b.signForm(f1);
			b.executeForm(f1);

			//Bureaucrat c(b);
			f1.beSigned(b);
			std::cout << f1;
		}
		catch(const std::exception& e)
		{
			std::cout << "Something goes wrong !!";
		}
	}
	// Robotomy
	{
		try
		{
			/* rqgs: 72, rqge: 45 */
			Bureaucrat b("bureaucrat 1", 137);
			RobotomyRequestForm r("home");
			
			r.beSigned(b);
			r.execute(b);

			b.executeForm(r);
			b.signForm(r);
			std::cout << r;
		}
		catch (const std::exception& e)
		{
			std::cout << "Something goes wrong !!";	
		}
	}
	// Presidential
	{
		try
		{
			/* rqs: 25, rqe: 5 */
			Bureaucrat b("bureaucrat 1", 137);
			PresidentialPardonForm p("home");
			Bureaucrat *b = new ();
			p.beSigned(b);
			p.execute(b);

			b.executeForm(p);
			b.signForm(p);
			
			std::cout << p;
		}
		catch (const std::exception& e)
		{
			std::cout << "Something goes wrong !!";	
		}
	}
	return (0);
}