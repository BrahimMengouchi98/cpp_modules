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

# include "iter.hpp"

int main()
{
	int arr1[] = {1, 2, 3, 4, 5};

    std::cout << "arr1: " << std::endl;
	std::cout << "before adding 2 to each element: " << std::endl;
    iter(arr1, 5, &print);
	std::cout << std::endl;
    iter(arr1, 5, &add_two);
	std::cout << "after adding 2 to each element: " << std::endl;
    iter(arr1, 5, &print);
	std::cout << std::endl;

}
