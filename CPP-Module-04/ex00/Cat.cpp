/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:15:27 by bmengouc          #+#    #+#             */
/*   Updated: 2023/09/05 21:15:28 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

void	Cat::makeSound(void) const
{
	std::cout << "Cat sound ...\n";
}

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat default constructor called\n";
}

Cat::Cat(Cat & copy)
{
	this->type = copy.type;
	std::cout << "Cat copy constructor called\n";
}

Cat & Cat::operator=(Cat const & src)
{
	this->type = src.type;
	std::cout << "Cat assignment operator called\n";
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
}
