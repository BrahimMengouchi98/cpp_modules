/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 06:28:28 by bmengouc          #+#    #+#             */
/*   Updated: 2023/12/31 06:28:29 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::ifstream	file("input.csv");
    std::string 	line;

	// skip first line
    std::getline(file, line);
    while (std::getline(file, line))
    {
        size_t delim = line.find('|');
        std::string date = trim(line.substr(0, delim));
        std::string value = trim(line.substr(delim + 1, line.length()));
        _data[date] = value;
    }
    file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    *this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _data = other._data;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool	BitcoinExchange::isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int	BitcoinExchange::ft_stoi(const std::string &str)
{
    std::stringstream ss(str);
    int value;

    ss >> value;

    return value;
}

double	BitcoinExchange::ft_stod(const std::string &str)
{
    std::stringstream	ss(str);
    double				value;

    ss >> value;

    return value;
}

std::string	BitcoinExchange::ft_to_string(int value)
{
    std::stringstream ss;

    ss << value;

    return ss.str();
}

std::string	BitcoinExchange::previousDate(const std::string& date) 
{
    int year = ft_stoi(date.substr(0, 4));
    int month = ft_stoi(date.substr(5, 2));
    int day = ft_stoi(date.substr(8, 2));

    // Days in each month (for non-leap years)
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	// February has 29 days in a leap year
    if (isLeapYear(year)) 
        daysInMonth[2] = 29;

    // Decrement the day
    day--;

    // Check if day is 0 (previous month)
    if (day == 0)
	{
        month--;
        // Check if month is 0 (December)
        if (month == 0) 
		{
            month = 12;
            year--;
        }
        day = daysInMonth[month];
    }

    // Format the previous date
    std::string newYear = ft_to_string(year);
    std::string newMonth, newDay;
    if (month < 10)
		newMonth = "0" + ft_to_string(month);
	else
		newMonth = ft_to_string(month);
	if (day < 10)
		newDay = "0" + ft_to_string(day);
	else 
		newDay = ft_to_string(day);

    return newYear + "-" + newMonth + "-" + newDay;
}

std::string	BitcoinExchange::trim(const std::string& str) 
{
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first)
        return str;

    size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}

bool	BitcoinExchange::fileExists(const std::string &filename)
{
    std::fstream file(filename);

    bool exists = file.good();

    file.close();
    return exists;
}

bool	BitcoinExchange::fileIsEmpty(const std::string &filename)
{
    std::ifstream file(filename);

    bool isEmpty = file.peek() == std::ifstream::traits_type::eof();

    file.close();
    return isEmpty;
}

int	BitcoinExchange::isDouble(const std::string& str)
{
	char*	endptr;

    strtod(str.c_str(), &endptr);

    // Check if the entire string was converted
    if (*endptr != '\0') 
	{
        return 0; // Not a valid double
    }

    // Check for valid double range
    double val = strtod(str.c_str(), nullptr);
    if (val == HUGE_VAL || val == -HUGE_VAL) 
	{
        return 0; // Not a valid double
    }
    return 1; // Valid double
}

int BitcoinExchange::isInteger(const std::string &str)
{
	char*	endptr;

    strtol(str.c_str(), &endptr, 10);

    // Check if the entire string was converted
    if (*endptr != '\0') 
	{
        return 0; // Not a valid integer
    }

    // Check for valid integer range
    long val = strtol(str.c_str(), nullptr, 10);
    if (val < INT_MIN || val > INT_MAX) 
	{
        return 0; // Not a valid integer within the int range
    }

    return 1; // Valid integer
}

void	BitcoinExchange::validateNumber(const std::string &str) 
{
    double	value;
    
	if (!isInteger(str) && !isDouble(str))
		throw std::invalid_argument("not a number => " + str);
	value = ft_stod(str);
    if (value < 0)
        throw std::invalid_argument("not a positive number.");

    if (value > 1000.0)
        throw std::invalid_argument("too large a number.");
}

bool	BitcoinExchange::isDigits(const std::string& str)
{
    for (size_t i = 0; i < str.length(); i++) 
	{
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

bool BitcoinExchange::validDate(const std::string &date)
{
    if (date.length() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);

	if (!isDigits(year) || !isDigits(month) || !isDigits(day))
		return false;

    int yearInt = ft_stoi(year);
	int monthInt = ft_stoi(month);
	int dayInt = ft_stoi(day);

    if ((yearInt < 2009 || yearInt > 2022) 
		|| (monthInt < 1 || monthInt > 12)
		|| (dayInt < 1 || dayInt > 31))
        return false;

    // Check for specific months with 30 days
    if ((monthInt == 4 || monthInt == 6 || monthInt == 9 || monthInt == 11) && dayInt > 30)
        return false;

    // Check for February
    if (monthInt == 2)
	{
        // Check for leap year
        bool isLeap = isLeapYear(yearInt);
		int a = isLeap ? 29 : 28;
        if (dayInt > a)
            return false;
    }
    return true;
}

void	BitcoinExchange::run(const std::string &filename)
{
    std::ifstream	file(filename);
    std::string		line;

	// check the file is exist
    if (!file.is_open())
	{
        std::cout << "Error: file does not exist" << std::endl;
        exit(EXIT_FAILURE);
    }
	
	// check the file is empty
    if (file.peek() == std::ifstream::traits_type::eof()) 
	{
        std::cout << "Error: file is empty" << std::endl;
        exit(EXIT_FAILURE);
    }

	// get the first line
    std::getline(file, line);

    if (line != "date | value")
	{
        std::cout << "Error: invalid file format" << std::endl;
        exit(EXIT_FAILURE);
    }

    while (std::getline(file, line))
    {
        size_t delim = line.find('|');
        if (delim == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

		std::string date = line.substr(0, delim);
		std::string value = line.substr(delim + 1);

		// Check for proper spacing
        if (date.back() != ' ' || value.front() != ' ')
        {
            std::cout << "Error: improper spacing => " << line << std::endl;
            continue;
        }

		date = trim(line.substr(0, delim));
        value = trim(line.substr(delim + 1));

        try
		{
            if (!validDate(date))
                throw std::invalid_argument("invalid date: " + (date.empty() ? "\"\"" : "'" + date + "'"));

            if(value.empty())
                throw std::invalid_argument("invalid value: " + (value.empty() ? "\"\"" : "'" + value + "'"));

            validateNumber(value);

            std::map<std::string, std::string>::iterator it;
            std::string prevDate = date;
            it = _data.find(date);

            while (it == _data.end())
			{
                const std::string& currentDate = prevDate;
                prevDate = previousDate(currentDate);
                it = _data.find(prevDate);
            }

            std::cout << date << " => " << value  << " = "
                << ft_stod(it->second) * ft_stod(value) << std::endl;
        } 
		catch (std::exception &e) 
		{
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    file.close();
}
