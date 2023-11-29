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

# include "ScavTrap.hpp"

int main()
{
	std::cout << "### TESTING CLAPTRAP ###\n" << std::endl;
	{
		ClapTrap a;
		ClapTrap b("'robot 1'");
		a.attack("'robot 1'");
		a.takeDamage(10);
		a.takeDamage(10);
		a.beRepaired(5);
		a.attack("'robot 2'");
		b.beRepaired(3);
		// for (int i = 0; i < 12; i++)
		// 	b.attack("'robot 3'");
		b.beRepaired(3);
	}

	std::cout << "\n\n### TESTING SCAVTRAP ###\n";
	{
		ScavTrap c;
		ScavTrap d("'robot 1'");
		c.attack("'robot 1'");
		// for (int i = 0; i < 10; i++)
		// 	c.attack("'robot 1'");
		c.beRepaired(22);
		c.takeDamage(21);
		c.beRepaired(22);
		c.guardGate();
		c.guardGate();
		d.attack("'robot 2'");
		d.takeDamage(101);
		d.takeDamage(15);
		d.attack("'robot 3'");
	}
}
