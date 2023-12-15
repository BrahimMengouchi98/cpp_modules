/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:48:34 by bmengouc          #+#    #+#             */
/*   Updated: 2023/12/01 18:48:35 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

int main()
{
	{
		std::cout << "---- TEST #1 -----" << std::endl;

		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		// print the span
		std::cout << sp << std::endl;

		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
	}

	{
		std::cout << "\n---- TEST #2 -----" << std::endl;

		try 
		{
			std::list<int>	l(10000);
			std::srand(time(NULL));
			std::generate(l.begin(), l.end(), std::rand);

			Span span(l.size());

			span.addNumber(l.begin(), l.end());

			std::cout << "sp: " << span << std::endl;
			std::cout << "shortest span: " << span.shortestSpan() << std::endl;
			std::cout << "longest span: " << span.longestSpan() << std::endl;
		} 
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl; 
		}
	}
	return 0;
}
