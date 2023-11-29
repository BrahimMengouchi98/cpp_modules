/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:20:09 by bmengouc          #+#    #+#             */
/*   Updated: 2023/08/23 11:20:10 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

void	Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::set_name(std::string name)
{
	this->name = name;
	std::cout << "Object Zombie with name: " << this->name << " was created\n";
}

Zombie::Zombie()
{
	this->name = "(null)";
	std::cout << "Object Zombie with name: " << this->name << " was created\n";
}
Zombie::~Zombie()
{
	std::cout << "Object Zombie with name: " << this->name << " was destroyed\n";
}
