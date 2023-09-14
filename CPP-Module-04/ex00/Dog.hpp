/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:14:49 by bmengouc          #+#    #+#             */
/*   Updated: 2023/09/05 21:14:50 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal
{
	public:
		Dog(void);
		Dog(Dog & copy);
		
		~Dog();
		
		Dog & operator=(Dog const & src);
		
		void	makeSound(void) const;
};

#endif
