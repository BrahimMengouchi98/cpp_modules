/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:34:07 by bmengouc          #+#    #+#             */
/*   Updated: 2023/12/08 21:34:08 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span& copy) {*this = copy;}

Span& Span::operator=(Span const &rhs) 
{
    if (this != &rhs)
	{
        this->_n = rhs._n;
        this->_list = rhs._list;
    }
    return *this;
}

Span::~Span(void) {}

std::list<int>* Span::getList(void)
{
    return &_list;
}

void	Span::addNumber(int num)
{
	if (_list.size() >= this->_n)
		throw std::out_of_range("Span::addNumber: list is full");
	_list.push_back(num);
}

void	Span::addNumber(std::list<int>::const_iterator itBegin, std::list<int>::const_iterator itEnd) 
{
    if ( _list.size() >= _n)
        throw std::out_of_range("Span::addNumber: list is full");
    _list.insert(_list.end(), itBegin, itEnd);
}

int    Span::longestSpan(void)
{	
    if (_list.size() < 2)
        throw std::out_of_range("Span::longestSpan: list is empty");
    return (*std::max_element( _list.begin(), _list.end()) 
		- *std::min_element(_list.begin(), _list.end()));
}

int Span::shortestSpan(void)
{
    if (_list.size() < 2)
        throw std::out_of_range("Span::shortestSpan: list is empty");
    int  min = Span::longestSpan();
    for (std::list<int>::const_iterator it = _list.begin(); it != _list.end(); ++it ) 
	{
        for (std::list<int>::const_iterator it2 = _list.begin(); it2 != _list.end(); ++it2 ) 
		{
            if (it == it2) 
				continue;
            if (std::abs(*it - *it2) < min)
                min = std::abs(*it - *it2);
        }
    }
    return min;
}

std::ostream& operator<<(std::ostream& os, Span& span) 
{
	// Iterate through the list using iterators
    for(std::list<int>::const_iterator it = span.getList()->begin(); 
		it != span.getList()->end(); ++it)
        os << *it << " ";
    return os;
}
