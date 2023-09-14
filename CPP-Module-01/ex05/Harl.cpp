# include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug()
{
	std::cout << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-special-";
	std::cout << "ketchup burger. I really do!\n";
}

void	Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn’t put enough bacon in my burger! If you did, ";
	std::cout << "I wouldn’t be asking for more!\n";
}

void	Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming for years whereas you started ";
	std::cout << "working here since last month.\n";	
}

void	Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void	Harl::complain(std::string level)
{
	int i = -1;
	void	(Harl::*ptr[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string complains[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	while (++i < 4)
	{
		if (complains[i] == level)
			(this->*ptr[i])();		
	}
	
}