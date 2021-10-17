/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 19:01:39 by ncolomer          #+#    #+#             */
/*   Updated: 2021/10/17 12:12:14 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

namespace ft
{
	
	template<class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
		while (first1 != last1) {
			if (first2 == last2 || *first2 < *first1)
				return (false);
			else if (*first1 < *first2)
				return (true);
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template<class value_type>
	value_type const &min(value_type const &a, value_type const &b) {
		return (a < b ? a : b);
	}

	template<class value_type>
	value_type const &max(value_type const &a, value_type const &b) {
		return (a < b ? b : a);
	}

	template<class value_type>
	bool equal(value_type const &a, value_type const &b) {
		return (a == b);
	}

	template<class value_type>
	bool less_than(value_type const &a, value_type const &b) {
		return (a < b);
	}

	template <class Key>
	struct less : std::binary_function <Key,Key,bool> {
		bool operator() (const Key & x, const Key & y) const {
			return (x < y);
		}
	};

	template<class value_type>
	bool more_than(value_type const &a, value_type const &b) {
		return (a > b);
	}

	template<bool B, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> { typedef T type; };

	template <typename T>
	struct is_integral { static const bool value = false; };

	template <>
	struct is_integral<bool> { static const bool value = true; };

	template <>
	struct is_integral<char> { static const bool value = true; };

	template <>
	struct is_integral<short> { static const bool value = true; };

	template <>
	struct is_integral<int> { static const bool value = true; };

	template <>
	struct is_integral<long> { static const bool value = true; };

	template <>
	struct is_integral<long long> { static const bool value = true; };

	template <>
	struct is_integral<unsigned char> { static const bool value = true; };

	template <>
	struct is_integral<unsigned short> { static const bool value = true; };

	template <>
	struct is_integral<unsigned int> { static const bool value = true; };

	template <>
	struct is_integral<unsigned long> { static const bool value = true; };

	template <>
	struct is_integral<unsigned long long> { static const bool value = true; };


	template <class Iterator>
		class iterator_traits
		{
			public:
				typedef typename Iterator::difference_type		difference_type;
				typedef typename Iterator::value_type			value_type;
				typedef typename Iterator::pointer				pointer;
				typedef typename Iterator::reference			reference;
				typedef typename Iterator::iterator_category	iterator_category;
		};
	template <class T>
		class iterator_traits<T*>
		{
			public:
				typedef ptrdiff_t								difference_type;
				typedef	T										value_type;
				typedef T*										pointer;
				typedef T&										reference;
				typedef std::random_access_iterator_tag				iterator_category;
		};
	template <class T>
		class iterator_traits<const T*>
		{
			public:
				typedef ptrdiff_t								difference_type;
				typedef	T										value_type;
				typedef const T*								pointer;
				typedef const T&								reference;
				typedef std::random_access_iterator_tag			iterator_category;	
		};

}

#endif
