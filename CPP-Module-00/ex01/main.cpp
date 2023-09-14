/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:04:34 by bmengouc          #+#    #+#             */
/*   Updated: 2023/08/21 17:04:39 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Phonebook.hpp"

int main()
{
	Phonebook	pb;
	std::string	choice;
	int			i;
	int 		size;
	int			check;

	check = 0;
	i = 0;
	size = 0;
	while (1)
	{
		if (i == 8)
		{
			i = 0;
			check = 1;
		}
		std::cout << "enter one of the following choices please: \n";
		std::cout << "----> \'ADD\' or \'SEARCH\' or \'EXIT\': ";
		std::getline(std::cin, choice);
		if ("ADD" == choice)
		{
			pb.add(i++);
			if (!check)
				size++;
		}
		else if ("SEARCH" == choice)
			pb.search(size);
		else if ("EXIT" == choice)
			break;
	}
}
