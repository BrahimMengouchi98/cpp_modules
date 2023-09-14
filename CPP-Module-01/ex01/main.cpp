/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:19:53 by bmengouc          #+#    #+#             */
/*   Updated: 2023/08/23 11:19:54 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int	main()
{
	int size = 5;
	Zombie *z = zombieHorde(size, "brahim");
	for (int i = 0; i < size; i++)
		z[i].announce();
	delete []z;
	return (0);
}
