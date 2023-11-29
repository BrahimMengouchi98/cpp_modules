/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:39:56 by bmengouc          #+#    #+#             */
/*   Updated: 2023/08/26 16:39:58 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"

int main()
{	
	std::cout << "\n\n==================   BASIC TEST   ==================\n" << std::endl;
	
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	
	dog->makeSound();
	cat->makeSound();

	std::cout << "\n\n==================   CLEAN ALL    ==================\n" << std::endl;
	delete dog;
	delete cat;
	
	//system("leaks ex01");

	// TEST DEEP COPY
	std::cout << "\n\n================== TEST DEEP COPY ==================\n" << std::endl;

	Cat luna;
	Cat bella;

	bella = luna;

	luna.getBrain()[0].setIdeas("hello", 0);
	std::cout << luna.getBrain()[0].getIdea(0) << "\n";
	std::cout << bella.getBrain()[0].getIdea(0) << "\n";

	//system("leaks ex01");

	std::cout << "\n\n================ SUBJECT ARRAY TEST ================\n" << std::endl;

	const Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
    for ( int i = 0; i < 4; i++ ) 
	{
        delete animals[i];
    }
	std::cout << "\n\n=====================\n\n";
	//system("leaks ex01");
}
