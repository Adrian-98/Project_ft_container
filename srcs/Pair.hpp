/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:51:21 by amunoz-p          #+#    #+#             */
/*   Updated: 2021/09/28 13:34:26 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

# include <cmath>
# include <string>
# include <iostream>
# include <istream>
# include <iomanip>
# include <ctype.h>
# include <ios>
# include <fstream>
# include <stdlib.h>
# include <sstream>
# include <memory>
# include <stdexcept>

namespace ft
{
	template <class T, class Y>
	class pair
	{
		public:
				T first;
				Y second;

				pair() {
					first = T();
					second = Y();
				}

				pair(const T & a, const Y & b) : first(a), second(b) {
				}

				pair(const pair & src) : first(src.first), second(src.second){
				}

				virtual	~pair() {}

				pair &	operator=(const pair & rhs) {
					first = rhs.first;
					second = rhs.second;
					return *this;
				}
		private:
	};

template <class T1, class T2>
  ft::pair<T1,T2> make_pair (T1 x, T2 y) {
	  return ft::pair<T1, T2>(x, y);
  }
}
#endif