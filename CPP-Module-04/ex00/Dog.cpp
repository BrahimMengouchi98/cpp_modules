/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:15:00 by bmengouc          #+#    #+#             */
/*   Updated: 2023/09/05 21:15:01 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

void Dog::makeSound() const
{
	std::cout << "Dog sound ...\n";
}

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog default constructor called\n";
}

Dog::Dog(Dog & copy)
{
	this->type = copy.type;
	std::cout << "Dog copy constructor called\n";
}

Dog & Dog::operator=(Dog const & src)
{
	this->type = src.type;
	std::cout << "Dog assignment operator called\n";
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
}
