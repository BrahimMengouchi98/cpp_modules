/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 07:38:21 by bmengouc          #+#    #+#             */
/*   Updated: 2023/12/31 07:38:23 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv) 
{

    if (argc < 2) 
	{
        std::cout << "Usage: " << argv[0] << " <positive integer sequence>" << std::endl;
        return EXIT_FAILURE;
    }

    try 
	{
        PmergeMe pmerge(argv + 1);
        std::cout << "Before:\t";
        pmerge.print_data();

        pmerge.sort_all();

        std::cout << "After:\t";
        pmerge.print_data();

        pmerge.benchmark();
    }
	catch (std::exception &e) 
	{
        std::cout << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}
