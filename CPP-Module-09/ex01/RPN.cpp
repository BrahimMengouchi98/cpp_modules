/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 07:01:42 by bmengouc          #+#    #+#             */
/*   Updated: 2023/12/31 07:01:52 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &var) { *this = var; }

RPN &RPN::operator=(const RPN &var)
{
	this->numbers = var.numbers;
	return (*this);
}

void	RPN::operation(int &a, int &b)
{
	b = numbers.top();
	numbers.pop();
	a = numbers.top();
	numbers.pop();
}

void	RPN::calculate(std::string input)
{
	int		a, b;
	char	c;
	int 	number;
	
	for (size_t i = 0; i < input.size(); i++)
	{
		c = input[i];

		// skip whitespace
		if (c == ' ')
			continue;
		else if (isdigit(c))
		{
			number = c - '0';
			numbers.push(number);
		}
		else if (c == '+' && numbers.size() >= 2)
		{
			operation(a, b);
			numbers.push(a + b);
		}
		else if (c == '-' && numbers.size() >= 2)
		{
			operation(a, b);
			numbers.push(a - b);
		}
		else if (c == '*' && numbers.size() >= 2)
		{
			operation(a, b);
			numbers.push(a * b);
		}
		else if (c == '/' && numbers.size() >= 2)
		{
			operation(a, b);
			numbers.push(a / b);
		}
		else
		{
			// invalid character or insufficient operands
			std::cout << "Invalid input." << std::endl;
			return;
		}
	}

	if (numbers.size() == 1)
	{
		int result = numbers.top();
		numbers.pop();
		std::cout << result << std::endl;
	}
	else
		std::cout << "Invalid input." << std::endl;
}
