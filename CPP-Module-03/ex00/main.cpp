/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:39:56 by bmengouc          #+#    #+#             */
/*   Updated: 2023/08/26 16:39:58 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

int main()
{
	std::cout << "### TESTING CLAPTRAP ###\n";
	{
		ClapTrap a;
		ClapTrap b("'main robot'");
		a.attack("'first robot'");
		a.takeDamage(10);
		a.takeDamage(10);
		a.beRepaired(5);
		a.attack("'second robot'");
		b.beRepaired(3);
		// for (int i = 0; i < 10; i++)
		// 	b.attack("'first robot'");
		b.beRepaired(3);
	}
	return (0);
}
