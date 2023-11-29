/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:50:56 by bmengouc          #+#    #+#             */
/*   Updated: 2023/11/27 21:50:59 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serializer.hpp"

// Constructors
Serializer::Serializer()
{
	std::cout << "Serializer Default Constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &src)
{
	std::cout << "Serializer Copy Constructor called" << std::endl;
	*this = src;
}

// Deconstructors
Serializer::~Serializer()
{
	std::cout << "Serializer Deconstructor called" << std::endl;
}

// Overloaded Operators
Serializer &Serializer::operator=(const Serializer &copy)
{
	std::cout << "Serializer Assignation operator called" << std::endl;
	if (this == &copy)
		return *this;
	return *this;
}

// Public Methods
uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

// Ostream overload
std::ostream	&operator<<(std::ostream &o, Data *a)
{
	o << "Address: " << static_cast<void*>(a) << std::endl;
	o << "Name: " << a->name << std::endl;
	o << "age: " << a->age << std::endl;
	return (o);
}
