/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:05:18 by bmengouc          #+#    #+#             */
/*   Updated: 2023/08/21 17:05:21 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

void	print_err()
{
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
}

void	print_msg(std::string av)
{
	int i;

	char c;
	i = 0;
	while (av[i])
	{
		c = std::toupper(av[i++]);
		std::cout << c;
	}
}

int main(int ac, char **av)
{
	int	i;

	if (ac < 2)
		print_err();
	else
	{
		i = 1;
		while (i < ac)
			print_msg(av[i++]);
	}
	std::cout << std::endl;
	return (0);
}
