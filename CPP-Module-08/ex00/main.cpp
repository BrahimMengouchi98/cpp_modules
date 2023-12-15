/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:33:28 by bmengouc          #+#    #+#             */
/*   Updated: 2023/12/08 21:33:29 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "easyfind.hpp"

#include <vector>
#include <list>

int main()
{
	int arr[] = {5, 2, 8, 1, 3};
	std::list<int> myVector(arr, arr + sizeof(arr) / sizeof(int));
	try
	{
		easyfind(myVector, 3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
}
