/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:33:57 by bmengouc          #+#    #+#             */
/*   Updated: 2023/12/08 21:33:58 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP

#define SPAN_HPP

# include <iostream>
# include <list>
#include <exception>

class Span
{
	private:
		unsigned	int	_n;
		std::list<int>	_list;
		Span(void);
	public:
		
		Span(unsigned int n);

    	~Span(void);
    	
		Span(const Span& copy);

		Span&	operator=(const Span& rhs);

		// members function
		void			addNumber(int num);
		void            addNumber(std::list<int>::const_iterator, std::list<int>::const_iterator);
		int     		longestSpan(void);
		int     		shortestSpan(void);
		std::list<int>*	getList(void);
};

std::ostream& operator<<(std::ostream&, Span&);

#endif
