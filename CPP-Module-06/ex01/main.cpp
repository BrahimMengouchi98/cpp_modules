/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:51:29 by bmengouc          #+#    #+#             */
/*   Updated: 2023/11/27 21:51:31 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serializer.hpp"

int main()
{
	Data ptr;
	
	ptr.name = "Brahim Mengouchi";
	ptr.age = 25;
	ptr.next = NULL;

	// print the info of ptr
	std::cout << std::endl;
	std::cout << "The original sturct: " << std::endl;
	std::cout << &ptr << std::endl;
	std::cout << "------------------------------" << std::endl;

	Data *reserialized_struct = Serializer::deserialize(Serializer::serialize(&ptr));

	// after deserialize
	std::cout << std::endl;
	std::cout << "The deserialized sturct: " << std::endl;
	std::cout << reserialized_struct;

	std::cout << std::endl;
	std::cout << "The original sturct: " << std::endl;
	std::cout << &ptr;
}
