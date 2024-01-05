/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 07:01:42 by bmengouc          #+#    #+#             */
/*   Updated: 2023/12/31 07:01:52 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
	private:

		std::stack<int>	numbers;
		void			operation(int &a, int &b);

	public:
		RPN();
		
		RPN(const RPN &var);
		
		~RPN();
		
		RPN &operator=(const RPN &var);

		void	calculate(std::string input);
};

#endif
