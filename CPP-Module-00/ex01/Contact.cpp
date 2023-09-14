/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:03:30 by bmengouc          #+#    #+#             */
/*   Updated: 2023/08/21 17:03:34 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Contact.hpp"

int	Contact::getIdx()
{
	return (this->idx);
}

void	Contact::setIdx(int idx)
{
	this->idx = idx;
}

std::string Contact::get_fname()
{
	return (this->_first_name);
}

std::string Contact::get_lname()
{
	return (this->_last_name);
}
std::string Contact::get_nname()
{
	return (this->_nick_name);
}

std::string Contact::get_pnum()
{
	return (this->_phone_number);
}

std::string Contact::get_dsercet()
{
	return (this->_dark_secret);
}

void	Contact::set_fname(std::string fn)
{
	this->_first_name = fn;
}

void	Contact::set_lname(std::string ln)
{
	this->_last_name = ln;
}

void	Contact::set_nname(std::string nn)
{
	this->_nick_name = nn;
}

void	Contact::set_pnum(std::string pn)
{
	this->_phone_number = pn;
}

void	Contact::set_dsercet(std::string ds)
{
	this->_dark_secret = ds;
}

void	Contact::add_contact(int idx)
{
	int			num;

	std::cout << "enter information for contact number: " << idx + 1 << "\n";
	this->setIdx(idx + 1);
	std::cout << "----> first name: ";
	std::getline(std::cin, this->_first_name);
	std::cout << "----> last name: ";
	std::getline(std::cin, this->_last_name);
	std::cout << "----> nick name: ";
	std::getline(std::cin, this->_nick_name);	
	while (1)
	{
		try
		{
			std::cout << "----> phone number: ";
			std::getline(std::cin, this->_phone_number);
			num = std::stoi(this->_phone_number);
			break;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Invalid argument!!\n";
		}
	}
	std::cout << "----> dark secret: ";
	std::getline(std::cin, _dark_secret);
	std::cout << this->_first_name << " " << this->_last_name;
	std::cout << " was added successfully to the Phonebook\n";
}
