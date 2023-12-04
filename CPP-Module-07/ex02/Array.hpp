/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 00:07:23 by bmengouc          #+#    #+#             */
/*   Updated: 2023/12/03 00:07:24 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
	private:
		T*				_arr;
		unsigned int	_size;
	public:
	
		// constructors
		Array()
		{
			_arr = new T();
			_size = 0;
		}

		Array(unsigned int n)
		{
			_arr = new T[n];
			_size = n;
		}

		// deconstructor
		~Array()
		{
			delete[] _arr;
		}

		// copy constructor
		Array(const Array& copy)
		{
			_arr = new T[copy.size()];
			_size =  copy.size();
			for (unsigned int i( 0 ); i < _size; i++)
				_arr[i] = copy._arr[i];
		}

		// copy assignment operator
		Array& operator=(const Array& rhs)
		{
			if (this != &rhs) 
			{
				delete [] _arr;
				_arr = new T[rhs.size()];
				_size = rhs._size;
				for (unsigned int i = 0; i < _size; i++)
					_arr[i] = rhs._arr[i];
        	}
        	return *this;
    	}
        
		T& operator[](unsigned int i) const
		{
			if (i >= _size)
				throw OutOfBoundsException();
			return _arr[i];
		}

		// member function
		unsigned int  size( void ) const { return _size; }

		class OutOfBoundsException : public std::exception 
		{
        	public:
           		virtual const char* what() const throw() 
				{ 
					return "Index is out of bounds";
				}
    	};
};

template<typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& arr)
{
	for (unsigned int i = 0; i < arr.size(); i++)
		out << arr[i] << " ";
	out << std::endl;
	return out;
}

# endif
