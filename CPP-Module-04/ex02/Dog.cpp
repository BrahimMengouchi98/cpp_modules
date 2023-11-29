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

Dog::Dog(void) : AAnimal("Dog")
{
	this->brain = new Brain();
	std::cout << "Dog default constructor called\n";
}

Dog::Dog(Dog & copy)
{
	this->brain = new Brain(*(copy.getBrain()));
	this->type = copy.type;
	std::cout << "Dog copy constructor called\n";
}

Dog & Dog::operator=(Dog const & src)
{
	this->type = src.type;
	
	// Delete the old Brain object (if any)
    delete this->brain;

	// shallow copy
    // this->brain = src.brain;

	// deep copy
	(*this).brain = new Brain(*(src.brain)); 

	std::cout << "Dog assignment operator called\n";
	return (*this);
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog destructor called\n";
}

Brain *Dog::getBrain( void ) const
{
	return (this->brain);
}

void Dog::makeSound() const
{
	std::cout << "Dog sound ...\n";
}

void Dog::compareTo(Dog const & other_dog) const
{
	std::cout << std::endl;
	std::cout << "Now comparing two dogs\n";
	std::cout << "My brain's heap address: " << static_cast<void*>(this->brain) << std::endl;
	std::cout << "Other's heap address: " << static_cast<void*>(other_dog.getBrain()) << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << ((this->brain)->getIdeas())[i] << " | " << ((other_dog.getBrain())->getIdeas())[i] << std::endl;
	std::cout << std::endl;
}
