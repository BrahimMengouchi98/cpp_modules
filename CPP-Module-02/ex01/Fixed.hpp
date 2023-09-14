/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:55:43 by bmengouc          #+#    #+#             */
/*   Updated: 2023/08/29 19:55:44 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					_val;
		static const int	_frac;
	public:
		Fixed(void);
		Fixed(const int val);
		Fixed(const float val);
		Fixed(const Fixed& copy);
		~Fixed();
		Fixed& operator=(const Fixed& copy);
		int 	getRawBits(void) const;
		void	setRawBits(int const val);
		float 	toFloat(void) const;
		int		toInt(void) const ;
};

std::ostream	&operator<<(std::ostream &str, Fixed const &fix_nbr);

#endif
