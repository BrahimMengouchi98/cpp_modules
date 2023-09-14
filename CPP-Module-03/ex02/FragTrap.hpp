/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:17:32 by bmengouc          #+#    #+#             */
/*   Updated: 2023/09/02 16:17:33 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

// classes

class FragTrap: public ClapTrap
{
	private:

	public:
	// Constructors
		FragTrap();
		FragTrap(const FragTrap &copy);
		FragTrap(std::string name);

	// Deconstructors
		~FragTrap();

	// Overloaded Operators
		FragTrap &operator=(const FragTrap &src);

	// Public Methods
		void highFiveGuys(void);
};

#endif