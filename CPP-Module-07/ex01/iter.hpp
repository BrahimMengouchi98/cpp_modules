/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:48:50 by bmengouc          #+#    #+#             */
/*   Updated: 2023/12/01 18:48:54 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	iter(T *arr, int size, void (*f)(T &))
{
	for (int i = 0; i < size; i++)
		f(arr[i]);
}
template < typename T>
void    add_two(T &i)
{
	i += 2;
}

template <typename T>
void    print(T i)
{
    std::cout << i << " ";
}

#endif
