/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:50:37 by bmengouc          #+#    #+#             */
/*   Updated: 2023/11/27 21:50:38 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

# include <iostream>
#include <cstdint>

typedef struct Data
{
	std::string name;
	int 		age;
	Data		*next;
} Data;


class Serializer
{
	private:
		Serializer();
		
	public:
		~Serializer();

		Serializer(const Serializer &copy);

		Serializer& operator=(const Serializer &copy);
	
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

// Ostream overload
std::ostream	&operator<<(std::ostream &o, Data *a);

#endif
