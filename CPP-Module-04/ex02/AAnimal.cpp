/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:14:34 by bmengouc          #+#    #+#             */
/*   Updated: 2023/09/05 21:14:35 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : type("AAnimal")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type)
{
	std::cout << "AAnimal constructor called\n";
}

AAnimal::AAnimal(AAnimal & copy)
{
	this->type = copy.type;
	std::cout << "AAnimal copy constructor called\n";
}

AAnimal & AAnimal::operator=(AAnimal const & src)
{
	this->type = src.type;
	std::cout << "AAnimal assignment operator called\n";
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called\n";
}

std::string AAnimal::getType(void) const
{
	return (this->type);
}

void	AAnimal::makeSound(void) const
{
	std::cout << "AAnimal sound ...\n";
}
