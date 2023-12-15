#ifndef MUTANTSTACK_HPP

#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename T, class Container = std::deque<T> >
class MutantStack : public std::stack< T, Container >
{
	private:

	public:

		MutantStack(void) {};
		~MutantStack(void) {};

		MutantStack(const MutantStack& rhs) {*this = rhs;}
		
		MutantStack&    operator=(const MutantStack& rhs) 
		{
			std::stack< T, Container >::operator=(rhs);
			return *this;
		}

		// Iterator Declaration
		typedef typename Container::iterator    iterator;

		// Iterator Member Functions
		iterator    begin() { return this->c.begin(); }
		iterator    end() { return this->c.end(); }
};

#endif