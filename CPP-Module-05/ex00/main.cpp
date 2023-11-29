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

int main()
{
	try
	{
		Bureaucrat b("bureaucrat 1", 149);
		// b.incrementGrade();
		b.decrementGrade();
		//Bureaucrat c(b);
		std::cout << b;
		//std::cout << c;
	}
	catch(const std::exception& e)
	{
		std::cout << "Something goes wrong !!";
	}
	return (0);
}
