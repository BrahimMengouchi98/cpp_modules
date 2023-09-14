/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:06:09 by bmengouc          #+#    #+#             */
/*   Updated: 2023/09/08 18:06:10 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongCat(void);
		WrongCat(std::string type);
		~WrongCat();

		std::string		getType(void) const;
		
		void	makeSound(void) const;
};

#endif
