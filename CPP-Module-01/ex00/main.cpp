/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:19:19 by bmengouc          #+#    #+#             */
/*   Updated: 2023/08/23 11:19:21 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie* newZombie( std::string name);
void randomChump( std::string name);

int	main()
{
	Zombie *z;
	
	randomChump("brahim");
	z = newZombie("bramen");
	z->announce();
	delete z;
	return (0);
}
