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
	this->brain = new Brain();
	std::cout << "Cat default constructor called\n";
}

Cat::Cat(Cat & copy)
{
	this->brain = new Brain(*(copy.getBrain())); // deep copy
	this->type = copy.type;
	std::cout << "Cat copy constructor called\n";
}

Cat & Cat::operator=(Cat const & src)
{
	this->type = src.type;
	
	// Delete the old Brain object (if any)
    delete this->brain;
	
	// shallow copy
    // this->brain = src.brain;

	// deep copy
	(*this).brain = new Brain(*(src.brain));
	std::cout << "Cat assignment operator called\n";
	return (*this);
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat destructor called\n";
}

Brain *Cat::getBrain( void ) const
{
	return (this->brain);
}

void Cat::compareTo(Cat const & other_cat) const
{
	std::cout << std::endl;
	std::cout << "Now comparing two cats\n";
	std::cout << "My brain's heap address: " << static_cast<void*>(this->brain) << std::endl;
	std::cout << "Other's heap address: " << static_cast<void*>(other_cat.getBrain()) << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << ((this->brain)->getIdeas())[i] << " | " << ((other_cat.getBrain())->getIdeas())[i] << std::endl;
	std::cout << std::endl;
}
