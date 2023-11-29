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
# include "Form.hpp"

int main()
{
	try
	{
		Form f1("form 1", 50, 60);
		Form f2("form 2", 50, 70);
		
		Bureaucrat b("bureaucrat 1", 50);
		// Bureaucrat c(b);

		b.signForm(f1);
		b.signForm(f2);
		std::cout << b;
		
		//f1.beSigned(b);
		//f2.beSigned(b);

		// std::cout << f1;
		// std::cout << f2;
	}
	catch(const std::exception& e)
	{
		std::cout << "Something goes wrong !!";
	}
	return (0);
}