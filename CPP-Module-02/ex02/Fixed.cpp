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

#include "Fixed.hpp"

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

const int	Fixed::_frac = 8;

Fixed::Fixed(void): _val(0)
{
}

Fixed::Fixed(const int value): _val(value * ft_pow(2, this->_frac))
{  
} 

Fixed::Fixed(const float value): _val(value * ft_pow(2, this->_frac))
{  
} 

Fixed::~Fixed(void)
{
}

Fixed::Fixed(Fixed const &copy)
{
	*this = copy;
}

float	Fixed::toFloat(void) const
{
	return (this->_val * ft_pow(2, -this->_frac));
}

int	Fixed::toInt(void) const
{
	return (this->_val * ft_pow(2, -this->_frac));
}

Fixed	&Fixed::operator=(Fixed const &copy)
{
	this->_val = copy.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(Fixed const &copy) const
{
	Fixed	result(this->toFloat() + copy.toFloat());
	return (result);
}

Fixed	Fixed::operator-(Fixed const &copy) const
{
	Fixed	result(this->toFloat() - copy.toFloat());
	return (result);
}

Fixed	Fixed::operator*(Fixed const &copy) const
{
	Fixed	result(this->toFloat() * copy.toFloat());
	return (result);
}

Fixed	Fixed::operator/(Fixed const &copy) const
{
	Fixed	result(this->toFloat() / copy.toFloat());
	return (result);
}

bool	Fixed::operator==(const Fixed &copy) const
{
	return (this->toFloat() == copy.toFloat());
}

bool	Fixed::operator!=(const Fixed &copy) const
{
	return (this->toFloat() != copy.toFloat());
}

bool	Fixed::operator<=(const Fixed &copy) const
{
	return (this->toFloat() <= copy.toFloat());
}

bool	Fixed::operator>=(const Fixed &copy) const
{
	return (this->toFloat() >= copy.toFloat());
}

bool	Fixed::operator<(const Fixed &copy) const
{
	return (this->toFloat() < copy.toFloat());
}

bool	Fixed::operator>(const Fixed &copy) const
{
	return (this->toFloat() > copy.toFloat());
}

// F++ ++F F-- --F
Fixed	&Fixed::operator++(void) // Prefix (++F)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	&Fixed::operator--(void) // Prefix (--F)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator++(int value) // Postfix (F++)
{
	Fixed	tmp;

	tmp = *this;

	if (!value)
		value = 1;
	this->setRawBits(this->getRawBits() + value);
	return (tmp);
}

Fixed	Fixed::operator--(int value) // Postfix (F--)
{
	Fixed	tmp;

	tmp = *this;

	if (!value)
		value = 1;
	this->setRawBits(this->getRawBits() - value);
	return (tmp);
}

const Fixed & Fixed::min(const Fixed & a, const Fixed & b)
{
	if (a < b)
		return (a);
	return (b);
}
	
const Fixed & Fixed::max(const Fixed & a, const Fixed & b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed & Fixed::min(Fixed & a, Fixed & b)
{
	if (a < b)
		return (a);
	return (b);
}
	
Fixed & Fixed::max(Fixed & a, Fixed & b)
{
	if (a > b)
		return (a);
	return (b);
}

int	Fixed::getRawBits(void) const
{
	return (this->_val);
}

void	Fixed::setRawBits(const int val)
{
	this->_val = val;
}

std::ostream	&operator<<(std::ostream &str, Fixed const &fix_nbr)
{
	return (str << fix_nbr.toFloat());
}
