/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:37:49 by bmengouc          #+#    #+#             */
/*   Updated: 2023/11/26 22:37:53 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Converter.hpp"

int ScalarConverter::i = 0;
float ScalarConverter::f = 0.0f;
double ScalarConverter::d = 0.0;
char ScalarConverter::c = '\0';

ScalarConverter::ScalarConverter(void)
{
    //std::cout << "ScalarConverter Default Constructor Called\n";
}

ScalarConverter::~ScalarConverter()
{
    //std::cout << "ScalarConverter Destructor Called\n";
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	//std::cout << "ScalarConverter Copy Constructor Called\n";
	*this = copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this != &other)
		*this = other;
	return (*this);
}

int ScalarConverter::isInteger(const std::string &str)
{
	char* endptr;
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

int	ScalarConverter::isFloat(const std::string& str)
{
   // Check if the last character is 'f'
    char lastChar = str[str.length() - 1];
    if (lastChar == 'f' || lastChar == 'F') 
	{
        // Remove the 'f' and check the remaining string
        std::string withoutF = str.substr(0, str.length() - 1);
        char* endptr;
        strtof(withoutF.c_str(), &endptr);

        // Check if the entire string (without 'f') was converted
        if (*endptr != '\0') 
		{
            return 0; // Not a valid float
        }
        // Check for valid float range
        float val = strtof(withoutF.c_str(), nullptr);
        if (val == HUGE_VALF || val == -HUGE_VALF) 
		{
            return 0; // Not a valid float
        }
        return 1; // Valid float
    }
	return 0;
}

int	ScalarConverter::isDouble(const std::string& str)
{
	char* endptr;
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

bool	isDisplayable(char c) 
{
    return (c >= 32 && c <= 126) || c == '\n' || c == '\t';
}

void	ScalarConverter::print()
{
	if (c > 126)
		std::cout << "char: Impossible"<< std::endl;
	else if (!isDisplayable(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	
	// Determine precision dynamically
    int precision = (f - i) ? 0 : 1;
	if (precision)
		std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void	ScalarConverter::print2(std::string conv)
{
	std::cout << "char: Impossible"<< std::endl;
	std::cout << "int: Impossible" << std::endl;
	if (conv == "nan" || conv == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (conv == "-inf" || conv == "-inff")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (conv == "+inf" || conv == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
}

int is_char(std::string str)
{
	return (str.length() == 1 
		&& ((str[0] >= 'a' && str[0] <= 'z')
		|| (str[0] >= 'A' && str[0] <= 'Z')));
}

void	ScalarConverter::toInteger(std::string conv)
{

	i = (int)strtol(conv.c_str(), nullptr, 10);
	c = 31;
	if (i >= 32 && i <= 126)
		c = static_cast<char>(i);
	else if (i > 126)
		c = 127;
	f = static_cast<float>(i);
	d = static_cast<double>(i);
	print();
}

void	ScalarConverter::toDouble(std::string conv)
{
	char* endptr;
	d = strtod(conv.c_str(), &endptr);
	
	// char
	c =  static_cast<char>(d);
	if (c > 126)
		std::cout << "char: Impossible"<< std::endl;
	else if (c < 32)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	
	// int
	long val = static_cast<long>(d);
	if (val < INT_MIN || val > INT_MAX) 
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << val << std::endl;
	
	// float
	f = static_cast<float>(d);
	if (f == HUGE_VALF || f == -HUGE_VALF)
		std::cout << "float: Impossible" << std::endl;
	else
	{
		if (f - static_cast<int>(f) == 0 )
			std::cout << "float: " << f << ".0f" << std::endl;
		else 
			std::cout << "float: " << f << "f" << std::endl;	
	}
	
	// double
	if (d - static_cast<int>(d) == 0)
			std::cout << "double: " << d << ".0" << std::endl;
	else 
		std::cout << "double: " << d << std::endl;
}

void	ScalarConverter::toFloat(std::string conv)
{
	f = strtof(conv.c_str(), nullptr);
	
	// char
	c =  static_cast<char>(f);
	if (c > 126)
		std::cout << "char: Impossible"<< std::endl;
	else if (c < 32)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	
	// int
	long val = static_cast<long>(f);
	if (val < INT_MIN || val > INT_MAX) 
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << val << std::endl;
	
	// float
	if (f - static_cast<int>(f) == 0)
			std::cout << "float: " << f << ".0f" << std::endl;
	else 
		std::cout << "float: " << f << "f" << std::endl;

	// double
	d = static_cast<double>(f);
	if (d == HUGE_VALF || d == -HUGE_VALF)
		std::cout << "double: Impossible" << std::endl;
	else
	{
		if (d - static_cast<int>(d) == 0 )
			std::cout << "double: " << d << ".0" << std::endl;
		else 
			std::cout << "double: " << d << std::endl;	
	}
}

void	ScalarConverter::toChar(std::string conv)
{
	c = conv[0];
	i = static_cast<int>(conv[0]);
	f = static_cast<float>(i);
	d = static_cast<double>(i);
	print();
}

bool    ScalarConverter::isLiterals(std::string conv) 
{
		if (conv == "nan" || conv == "nanf" 
		|| conv == "-inf" || conv == "-inff"
		|| conv == "+inf" || conv == "+inff")
            return true;
    return false;
}

void ScalarConverter::convert(std::string conv)
{
	if (isLiterals(conv))
	{
		print2(conv);
		return ;
	}
	if (isInteger(conv))
	{
		toInteger(conv);
		return ;
	}
	else if (isDouble(conv))
	{
		toDouble(conv);
		return ;
	}
	else if (isFloat(conv))
	{
		toFloat(conv);
		return ;
	}
	else if (is_char(conv))
	{
		toChar(conv);
		return ;
	}
	else
		std::cout << "Error: Unknown type" << std::endl;
}
