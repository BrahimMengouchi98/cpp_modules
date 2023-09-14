/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:14:21 by bmengouc          #+#    #+#             */
/*   Updated: 2023/09/05 21:14:21 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_HPP
# define AAnimal_HPP

#include <iostream>
#include <string.h>

class AAnimal
{
	protected:
		std::string	type;
	public:
		AAnimal(void);
		AAnimal(std::string type);
		AAnimal(AAnimal & copy);
		
		virtual ~AAnimal() = 0;

		AAnimal & operator=(AAnimal const & src);

		std::string		getType(void) const;
		virtual void	makeSound(void) const = 0;
};

#endif
