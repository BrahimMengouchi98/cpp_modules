/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:56:35 by bmengouc          #+#    #+#             */
/*   Updated: 2023/08/29 19:57:12 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

static	float ft_pow(float base, int exp)
{
	float	result;

	if (!exp)
		return (1);
	if (exp < 0)
	{
		base = 1 / base;
		exp *= -1;
	}
	result = base;
	while (--exp)
		result *= base;
	return (result);
}

const int Fixed::_frac = 8;

Fixed::Fixed():_val(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int val) : _val(val * ft_pow(2, this->_frac))
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float val) : _val(val * ft_pow(2, this->_frac))
{
	std::cout << "Float constructor called\n";
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called\n";
	*this = copy;
}

int		Fixed::toInt(void) const
{
	return (this->_val * ft_pow(2, -this->_frac));
}

float	Fixed::toFloat(void) const
{
	return (this->_val * ft_pow(2, -this->_frac));
}

Fixed& Fixed::operator=(const Fixed& copy)
{
	std::cout << "Copy assignment operator called\n";
	this->_val = copy._val;
	return (*this);
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called\n";
	return (this->_val);
}

void	Fixed::setRawBits(int const val)
{
	this->_val = val;
}

std::ostream	&operator<<(std::ostream &str, Fixed const &fix_nbr)
{
	return (str << fix_nbr.toFloat());
}
