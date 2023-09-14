/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:14:34 by bmengouc          #+#    #+#             */
/*   Updated: 2023/09/05 21:14:35 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal constructor called\n";
}

Animal::Animal(Animal & copy)
{
	this->type = copy.type;
	std::cout << "Animal copy constructor called\n";
}

Animal & Animal::operator=(Animal const & src)
{
	this->type = src.type;
	std::cout << "Animal assignment operator called\n";
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called\n";
}

std::string Animal::getType(void) const
{
	return (this->type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal sound ...\n";
}
