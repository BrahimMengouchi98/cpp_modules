/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:07:10 by bmengouc          #+#    #+#             */
/*   Updated: 2023/09/08 18:07:22 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	this->ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "brahim brain :)";
	std::cout << "Brain default constructor called\n";
}

Brain::~Brain()
{
	delete [] (this->ideas);
	std::cout << "Brain destructor called\n";
}

Brain::Brain(Brain & copy)
{
	std::string *copy_ideas = copy.getIdeas();
	this->ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy_ideas[i];
	std::cout << "Brain copy constructor called\n";
}

Brain & Brain::operator=(Brain const & src)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
	std::cout << "Brain assignment operator called\n";
	return (*this);
}

std::string *Brain::getIdeas()
{
	return (this->ideas);
}

std::string Brain::getIdea(int idx)
{
	return (this->ideas[idx]);
}

void Brain::setIdeas(const std::string idea, int idx)
{
    ideas[idx] = idea;
}
