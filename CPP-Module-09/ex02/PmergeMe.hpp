/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 07:38:56 by bmengouc          #+#    #+#             */
/*   Updated: 2023/12/31 07:38:57 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>
#include <sstream>

/* Class definition */
class PmergeMe 
{

	public:
	    
		// A pair of values of the container's value type
		typedef std::pair <int, int>	type_pair;
		
		// A vector of pairs
		typedef std::vector <type_pair>	pair_vector;

	private:

		std::vector<int>	_data_v;
		std::deque<int>  	_data_dq;
		int  				_last;
		double      		_time1;
		double      		_time2;

		std::vector<int>	generate_indexes(size_t n);
		pair_vector			generate_pairs_v(std::vector<int> data_v);
		pair_vector			generate_pairs_dq(std::deque<int> data_dq);
		void        		sort_pairs(pair_vector &pairs);
		int         		binary_search_v(int target);
		int         		binary_search_dq(int target);
		int         		ft_stoa(const char *str);
		bool        		is_number(const std::string& s);

		public:
			
			PmergeMe();
			PmergeMe(char **data);

			PmergeMe(const PmergeMe &other);
			PmergeMe &operator=(const PmergeMe &other);

			~PmergeMe();

			void	sort_all();
			void	sort_vector(std::clock_t start, std::vector<int> insertionIndexes);
			void	sort_deque(std::clock_t start, std::vector<int> insertionIndexes);
			void	print_data() const;
			void	benchmark() const;

};

#endif
