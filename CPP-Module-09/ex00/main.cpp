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

# include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: could not open file" << std::endl;
		return (EXIT_FAILURE);
	}
	
	BitcoinExchange exchange;

	exchange.run(av[1]);

	return (EXIT_SUCCESS);
}
