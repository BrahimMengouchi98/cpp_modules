/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 07:39:57 by bmengouc          #+#    #+#             */
/*   Updated: 2023/12/31 07:39:58 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// default constructor
PmergeMe::PmergeMe() : _data_v(), _data_dq(), _last(-1), _time1(0), _time2(0) {}

PmergeMe::PmergeMe(char **data) : _data_v(), _data_dq() 
{
    _time1 = 0;
    _time2 = 0;
    _last = -1;

    for(size_t i = 0; data[i]; i++)
	{
        if (!is_number(data[i]))
            throw std::invalid_argument("Error");

        _data_v.push_back(ft_stoa(data[i]));
        _data_dq.push_back(ft_stoa(data[i]));
    }
}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe &other) 
{
    _data_v = other._data_v;
    _data_dq = other._data_dq;
}

// Copy assignment operator
PmergeMe &PmergeMe::operator=(const PmergeMe &other) 
{
    if (this != &other) 
	{
        _data_v = other._data_v;
		_data_dq = other._data_dq;
        _last = other._last;
        _time1 = other._time1;
        _time2 = other._time2;
    }
    return *this;
}

// Destructor
PmergeMe::~PmergeMe() {}

PmergeMe::pair_vector PmergeMe::generate_pairs_v(std::vector<int> data_v) 
{
    pair_vector pairs;

    // If the size of the data is odd, we need to store the last element
    if (data_v.size() % 2 != 0)
	{
        _last = data_v.back();
        data_v.pop_back();
    }

    for (size_t i = 0; i < data_v.size(); i += 2)
	{
        // If the first element is greater than the second, swap them
        if (data_v[i] > data_v[i + 1])
            std::swap(data_v[i], data_v[i + 1]);

        pairs.push_back(std::make_pair(data_v[i], data_v[i + 1]));
    }

    return pairs;
}

PmergeMe::pair_vector PmergeMe::generate_pairs_dq(std::deque<int> data_dq) 
{
    pair_vector pairs;

    // If the size of the data is odd, we need to store the last element
    if (data_dq.size() % 2 != 0)
	{
        _last = data_dq.back();
        data_dq.pop_back();
    }

    for (size_t i = 0; i < data_dq.size(); i += 2)
	{
        // If the first element is greater than the second, swap them
        if (data_dq[i] > data_dq[i + 1])
            std::swap(data_dq[i], data_dq[i + 1]);

        pairs.push_back(std::make_pair(data_dq[i], data_dq[i + 1]));
    }

    return pairs;
}

// Recursive function to sort pairs
void	PmergeMe::sort_pairs(pair_vector &pairs)
{
    if (pairs.size() <= 1)
        return; // Base case: Nothing to sort

    // Divide the vector into two halves
    size_t middle = pairs.size() / 2;
    pair_vector leftHalf(pairs.begin(), pairs.begin() + middle);
    pair_vector rightHalf(pairs.begin() + middle, pairs.end());

    // Recursively sort the two halves
    sort_pairs(leftHalf);
    sort_pairs(rightHalf);

    // Merge the sorted halves
    size_t leftIdx = 0;
    size_t rightIdx = 0;
    size_t idx = 0;

    while (leftIdx < leftHalf.size() && rightIdx < rightHalf.size())
	{
        if (leftHalf[leftIdx].second < rightHalf[rightIdx].second)
			pairs[idx++] = leftHalf[leftIdx++];
		else 
			pairs[idx++] = rightHalf[rightIdx++];
	}

    while (leftIdx < leftHalf.size()) 
        pairs[idx++] = leftHalf[leftIdx++];

    while (rightIdx < rightHalf.size())
        pairs[idx++] = rightHalf[rightIdx++];
}

int	PmergeMe::binary_search_v(int target) 
{
    int left = 0;
    int right = _data_v.size() - 1;

    while (left <= right)
	{
        int middle = (left + right) / 2;

        if (_data_v[middle] == target)
            return middle;
        else if (_data_v[middle] < target)
            left = middle + 1;
        else
            right = middle - 1;
    }

    return left;
}

int	PmergeMe::binary_search_dq(int target) 
{
    int left = 0;
    int right = _data_dq.size() - 1;

    while (left <= right)
	{
        int middle = (left + right) / 2;

        if (_data_dq[middle] == target)
            return middle;
        else if (_data_dq[middle] < target)
            left = middle + 1;
        else
            right = middle - 1;
    }

    return left;
}

std::vector<int> PmergeMe::generate_indexes(size_t size) 
{
    std::vector<int>	indexes;
    int 				jacobsthalSequence[size];

    jacobsthalSequence[0] = 0;
    jacobsthalSequence[1] = 1;
	indexes.push_back(jacobsthalSequence[0]);
	indexes.push_back(jacobsthalSequence[1]);
    for (size_t i = 2; indexes.size() < size; i++)
    {
        // Generate the next Jacobsthal number
        jacobsthalSequence[i] = jacobsthalSequence[i - 1] + 2 * jacobsthalSequence[i - 2];

        // Push the jacobsthal number
		if (i != 2)
			indexes.push_back(jacobsthalSequence[i]);
    }
    return (indexes);
}

void	PmergeMe::print_data() const
{
    for (size_t i = 0; i < _data_v.size(); i++)
        std::cout << _data_v[i] << " ";

    std::cout << std::endl;
}

void	PmergeMe::benchmark() const 
{
	std::cout
            <<	"Time to process a range of " << _data_v.size()
            << " elements with std::" << "vector<int>"
            << " : " << std::fixed << std::setprecision(5) << _time1 << " us"
            << std::endl;
	std::cout
            <<	"Time to process a range of " << _data_dq.size()
            << " elements with std::" << "deque<int>"
            << " : " << std::fixed << std::setprecision(5) << _time2 << " us"
            << std::endl;
}

// template<typename Container>
int	PmergeMe::ft_stoa(const char *str) 
{
    std::istringstream  ss(str);
    int                 number;

    ss >> number; // Convert the string

    return (number);
}

// template<typename Container>
bool	PmergeMe::is_number(const std::string& s)
{
    if (s.empty() || s[0] == '-')
        return false;

    size_t i = 0;

    if (s[0] == '+' && s.length() == 1)
        return false;
    else if (s[0] == '+')
        i++;

    for (; i < s.length(); i++) 
	{
        if (!std::isdigit(s[i]))
            return false;
    }

    return true;
}

void	PmergeMe::sort_vector(std::clock_t start, std::vector<int> insertionIndexes)
{
	pair_vector pairs = generate_pairs_v(_data_v);
    // If the input is empty, we just need to push the last element
    if (pairs.size() == 0)
	{
        _data_v.push_back(_last);
        _time1 = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC;
        return;
    }

    sort_pairs(pairs);

    _data_v.clear();

    _data_v.push_back(pairs[0].first);

    for (size_t i = 0; i < pairs.size(); i++)
        _data_v.push_back(pairs[i].second);

	int lastJacobsthalNumber = -1, begin, index;

	for (size_t i = 0; i < insertionIndexes.size(); i++)
    { 
        if (size_t(insertionIndexes[i]) <= pairs.size())
		{
			begin = insertionIndexes[i];
			if (size_t(insertionIndexes[i]) == pairs.size())
				begin = insertionIndexes[i] - 1;
			for (int j = begin; j > lastJacobsthalNumber; j--)
			{
				if (j != 0)
				{
					index = binary_search_v(pairs[j].first);
					_data_v.insert(_data_v.begin() + index, pairs[j].first);
				}
			}
			lastJacobsthalNumber = insertionIndexes[i];
		}
    }

    if (_last != -1)
	{
        index = binary_search_v(_last);
        _data_v.insert(_data_v.begin() + index, _last);
    }

    _time1 = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC;
}

void	PmergeMe::sort_deque(std::clock_t start, std::vector<int> insertionIndexes)
{
	pair_vector pairs = generate_pairs_dq(_data_dq);
    // If the input is empty, we just need to push the last element
    if (pairs.size() == 0)
	{
        _data_dq.push_back(_last);
        _time2 = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC;
        return;
    }

    sort_pairs(pairs);

    _data_dq.clear();

    _data_dq.push_back(pairs[0].first);

    for (size_t i = 0; i < pairs.size(); i++)
        _data_dq.push_back(pairs[i].second);

	int lastJacobsthalNumber = -1, begin, index;

	for (size_t i = 0; i < insertionIndexes.size(); i++)
    { 
        if (size_t(insertionIndexes[i]) <= pairs.size())
		{
			begin = insertionIndexes[i];
			if (size_t(insertionIndexes[i]) == pairs.size())
				begin = insertionIndexes[i] - 1;
			for (int j = begin; j > lastJacobsthalNumber; j--)
			{
				if (j != 0)
				{
					index = binary_search_dq(pairs[j].first);
					_data_dq.insert(_data_dq.begin() + index, pairs[j].first);
				}
			}
			lastJacobsthalNumber = insertionIndexes[i];
		}
    }

    if (_last != -1)
	{
        index = binary_search_dq(_last);
        _data_dq.insert(_data_dq.begin() + index, _last);
    }

    _time2 = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC;
}

void	PmergeMe::sort_all()
{
	std::clock_t start = std::clock();

    std::vector<int>	insertionIndexes = generate_indexes(_data_v.size());
	sort_vector(start, insertionIndexes);
	sort_deque(start, insertionIndexes);
}
