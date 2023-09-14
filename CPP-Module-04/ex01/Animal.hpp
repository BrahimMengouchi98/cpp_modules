/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:14:21 by bmengouc          #+#    #+#             */
/*   Updated: 2023/09/05 21:14:21 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string.h>

class Animal
{
	protected:
		std::string	type;
	public:
		Animal(void);
		Animal(std::string type);
		Animal(Animal & copy);
		
		virtual ~Animal();

		Animal & operator=(Animal const & src);

		std::string		getType(void) const;
		virtual void	makeSound(void) const;
};

#endif
