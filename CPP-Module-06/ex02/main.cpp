/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:14:12 by bmengouc          #+#    #+#             */
/*   Updated: 2023/11/28 18:14:13 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib> // for std::rand
#include <ctime>   // for std::time

Base*	generate()
{
    int randomValue = std::rand() % 3;

    if (randomValue == 0)
        return new A();
    else if (randomValue == 1)
        return new B();
    else
        return new C();
}

void    identify(Base* p) 
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void    identify(Base& p) 
{
    try 
	{
        A& a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void)a;
    } 
	catch(const std::exception& e) {}
    try 
	{
        B& b = dynamic_cast<B&>( p );
        std::cout << "B" << std::endl;
        (void)b;
    } 
	catch(const std::exception& e) {}
    try 
	{
        C& c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        (void)c;
    } 
	catch(const std::exception& e) {}
}

int main()
{
	std::srand(std::time(0)); // Seed the random number generator
	
	Base *a = generate();
	
	std::cout << "a* = "; identify(a);
	std::cout << "&a = "; identify(*a);

	delete a;
}
