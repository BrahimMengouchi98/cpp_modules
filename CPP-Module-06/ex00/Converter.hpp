/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:37:04 by bmengouc          #+#    #+#             */
/*   Updated: 2023/11/26 22:37:05 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
#define CONVERTER_HPP

# include <iostream>
# include <string>
# include <limits>
# include <cstdlib>
# include <cmath>
# include <iomanip>

class ScalarConverter
{
	private:

		static int		i;
		static float	f;
		static double	d;
		static char		c;

		static int 		isFloat(const std::string& str);
		static int 		isDouble(const std::string& str);
		static int 		isInteger(const std::string& str);

		static	void 	toFloat(std::string conv);
		static  void 	toDouble(std::string conv);
		static  void	toInteger(std::string conv);
		static  void	toChar(std::string conv);


		static	void	print();
		static	void	print2(std::string conv);

		static	bool	isLiterals(std::string conv);
		
		// Make the constructor private
		ScalarConverter();
	public:

		~ScalarConverter();

		// copy constuctor
		ScalarConverter(const ScalarConverter &copy);

		// Assignment operator
		ScalarConverter& operator=(const ScalarConverter &other);

		// Members Functions
		static void convert(std::string conv);
};

#endif
