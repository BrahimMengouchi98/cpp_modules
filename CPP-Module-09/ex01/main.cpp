/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 07:10:07 by bmengouc          #+#    #+#             */
/*   Updated: 2023/12/31 07:37:33 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char* argv[]) 
{
    if (argc != 2) 
	{
        std::cout << "Usage: rpn_calculator <expression>" << std::endl;
        return 1;
    }

    std::string input = argv[1];
    RPN calculator;
    calculator.calculate(input);

    return 0;
}
