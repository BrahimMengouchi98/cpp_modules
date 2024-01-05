/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 06:28:39 by bmengouc          #+#    #+#             */
/*   Updated: 2023/12/31 06:28:40 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP

#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
# include <cmath>

class BitcoinExchange
{
	private:

		std::map<std::string, std::string>    _data;

		std::string  previousDate(const std::string& date);
		std::string  trim(const std::string& str);

		void    	validateNumber(const std::string &str);
		bool    	fileExists(const std::string &filename);
		bool    	fileIsEmpty(const std::string &filename);
		bool    	validDate(const std::string &date);
		bool    	isLeapYear(int year);
		bool		isDigits(const std::string& str);
		int     	ft_stoi(const std::string &str);
		double  	ft_stod(const std::string &str);
		int			isDouble(const std::string& str);
		int			isInteger(const std::string& str);

		std::string	ft_to_string(int value);

	public:
		
		BitcoinExchange();
		
		BitcoinExchange(const BitcoinExchange &copy);
		
		BitcoinExchange &operator=(const BitcoinExchange &other);
		
		~BitcoinExchange();

		void	run(const std::string &filename);

};

#endif
