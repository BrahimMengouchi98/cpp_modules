/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 00:07:46 by bmengouc          #+#    #+#             */
/*   Updated: 2023/12/03 00:07:47 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define SIZE 10

int main()
{	
	std::cout << "-----------------------------" << std::endl;
	const Array<int> integers(SIZE);
	Array<int> integers2(SIZE - 5);

	// fill the array
	for (unsigned int i = 0; i < integers.size(); i++)
		integers[i] = i;
	
	// print the first array
	std::cout << integers;
	
	integers2 = integers;

	// print the second array
	std::cout << integers2;

	try
	{
		std::cout << "non valid access: ";
		std::cout << integers[SIZE];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "non valid access: " << integers[SIZE];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "valid access: " << integers[SIZE - 1] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "-----------------------------" << std::endl;

    return 0;
}
