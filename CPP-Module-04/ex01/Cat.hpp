/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:15:16 by bmengouc          #+#    #+#             */
/*   Updated: 2023/09/05 21:15:18 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain	*brain;
	public:
		Cat(void);
		Cat(Cat & copy);

		~Cat();
		
		Cat & operator=(Cat const & src);
		
		void	makeSound(void) const;
		Brain  	*getBrain( void ) const;
		void 	compareTo(Cat const & other_cat) const;
};

#endif
