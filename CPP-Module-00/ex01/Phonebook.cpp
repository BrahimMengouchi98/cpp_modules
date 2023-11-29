/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:03:58 by bmengouc          #+#    #+#             */
/*   Updated: 2023/08/21 17:04:00 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Phonebook.hpp"

void	Phonebook::add(int idx)
{
	this->contacts[idx].add_contact(idx);
}

void	put_header()
{
	int i;

	i = -1;
	while (++i < 45)
	{
		if (i == 0 || i == 44)
			std::cout << ' ';
		else 
		std::cout << '-';
	}
	std::cout << "\n|     Index";
	std::cout << "|First Name";
	std::cout << "| Last Name";
	std::cout << "|  Nickname|\n";
	i = -1;
	while (++i < 45)
	{
		if (i== 0 || i == 11 || i == 22 || i == 33 || i == 44)
			std::cout << '|';
		else 
			std::cout << '-';
	}
	std::cout << "\n";
}

void	put_footer()
{
	int i;

	i = -1;
	while (++i < 45)
	{
		if (i == 0 || i == 44)
			std::cout << ' ';
		else
			std::cout << '-';
	}
	std::cout << "\n";
}

void	truncate(std::string str)
{
	int i;

	i = -1;
	while (++i < 9)
		std::cout << str[i];
	std::cout << ".|";
}

void	put_body(Contact contacts[], int i)
{
	int	j;
	int k;
		
	std::cout << "|         " << contacts[i].getIdx() << "|";
	if (contacts[i].get_fname().length() <= 10)
	{
		k = -1;
		j = 10 - contacts[i].get_fname().length();
		while (++k < j)
			std::cout << " ";
		std::cout << contacts[i].get_fname() << "|";
	}
	else
		truncate(contacts[i].get_fname());
	if (contacts[i].get_lname().length() <= 10)
	{
		k = -1;
		j = 10 - contacts[i].get_lname().length();
		while (++k < j)
			std::cout << " ";
		std::cout << contacts[i].get_lname() << "|";
	}
	else
		truncate(contacts[i].get_lname());
	if (contacts[i].get_nname().length() <= 10)
	{
		k = -1;
		j = 10 - contacts[i].get_nname().length();
		while (++k < j)
			std::cout << " ";
		std::cout << contacts[i].get_nname() << "|\n";
	}
	else
	{
		truncate(contacts[i].get_nname());
		std::cout << std::endl;
	}
}

void	print_contact(Contact contacts[], int i)
{
	std::cout << "----> First Name: ";
	std::cout << contacts[i].get_fname() << "\n";
	std::cout << "----> Last Name: ";
	std::cout << contacts[i].get_lname() << "\n";
	std::cout << "----> Nick Name: ";
	std::cout << contacts[i].get_nname() << "\n";
	std::cout << "----> Phone Number: ";
	std::cout << contacts[i].get_pnum() << "\n";
	std::cout << "----> Dark Secret: ";
	std::cout << contacts[i].get_dsercet() << "\n";	
}

void	Phonebook::search(int size)
{
	int i;
	std::string str;

	if (!size)
	{
	 	std::cout << "Phonbook is empty !!\n";
		return ;
	}
	i = -1;
	put_header();
	while (++i < size)
        put_body(this->contacts, i);
	put_footer();
	while (1)
	{
		try
		{
			std::cout << "Select an index: ";
			std::getline(std::cin, str);
			i = std::stoi(str);
			str.clear();
			if (i >= 1 && i <= size)
			{
				print_contact(this->contacts, i - 1);
				break;
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << "Invalid argument!!\n";
		}
	}
}
