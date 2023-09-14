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
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"

int main()
{
	std::cout << "\n\n----------> Calling Constructros <---------\n\n";

	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

    std::cout << "\n\n----------> Types <---------\n\n";
	
	std::cout << animal->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;

	std::cout << "\n\n----------> Sounds <---------\n\n";
	
	animal->makeSound();
	dog->makeSound();
	cat->makeSound();

	std::cout << "\n\n----------> Calling Destructros <---------\n\n";
	
	delete animal;
	delete dog;
	delete cat;
	
	std::cout << "\n\n----------> Calling Constructros <---------\n\n";
	
	const WrongAnimal* wrong_animal = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat();
	
	std::cout << "\n\n----------> Sounds <---------\n\n";
	
	wrong_animal->makeSound();
	wrong_cat->makeSound();

	std::cout << "\n\n----------> Calling Destructros <---------\n\n";
	
	delete wrong_animal;
	delete wrong_cat;
}
