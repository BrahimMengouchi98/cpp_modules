/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:33:19 by bmengouc          #+#    #+#             */
/*   Updated: 2023/12/08 21:33:21 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP

# define EASYFIND_HPP

#include <iostream>
#include <stdexcept>
#include <sstream>

template <typename T>
void	easyfind(T t, int valueToFind)
{
	// Use std::find to search for the value in the vector
    typename T::iterator it = std::find(t.begin(), t.end(), valueToFind);

    // Check if the value was found
    if (it != t.end())
        std::cout << "Value " << valueToFind 
			<< " found !!" << std::endl;
	else
	{
        std::ostringstream oss;
        oss << "Value " << valueToFind << " not found !!";
        // Throw an std::runtime_error with the value in the error message
        throw std::runtime_error(oss.str());
	}
}

#endif
