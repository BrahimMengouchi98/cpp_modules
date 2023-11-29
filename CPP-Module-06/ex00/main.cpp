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

# include "Converter.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		const std::string& inputString(av[1]);
		ScalarConverter::convert(inputString);
	}
	return (0);
}