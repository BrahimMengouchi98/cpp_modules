/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:27:17 by bmengouc          #+#    #+#             */
/*   Updated: 2023/08/23 11:27:18 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <fstream>

std::string replaceWord(std::string line, std::string sw, std::string rw) 
{
    size_t pos = 0;
    size_t	prevPos = 0;

	while ((pos = line.find(sw, prevPos)) != std::string::npos)
	{
		line = line.erase(pos, sw.length());
		line.insert(pos, rw);
		prevPos += sw.length();
	}
    return (line);
}


int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "wrong number of paramaters !!\n";
		return (0);	
	}
	std::string str;
	std::ifstream inputFile(av[1]);
	if (!inputFile.is_open())
	{
		std::cout << "Failed to open input file." << std::endl;
		return 1;
	}
	std::string newFile = av[1];
	newFile.append(".replace");
	std::ofstream outputFile(newFile);
	std::string sw = av[2];
	std::string rw = av[3];
	while (std::getline(inputFile, str))
	{
		if (str.find(sw) != std::string::npos)
			str = replaceWord(str, sw, rw);
		outputFile << str << std::endl;
	}
	inputFile.close();
	outputFile.close();
	return (0);
}
