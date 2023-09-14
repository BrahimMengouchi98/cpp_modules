/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:06:57 by bmengouc          #+#    #+#             */
/*   Updated: 2023/09/08 18:06:58 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string	*ideas;
	public:
		Brain();
		Brain(Brain & copy);

		~Brain();
		
		Brain & operator=(Brain const & src);
		
		std::string *getIdeas();
		std::string getIdea(int idx);
		void setIdeas(const std::string idea, int idx);
};

#endif
