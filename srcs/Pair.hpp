/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:51:21 by amunoz-p          #+#    #+#             */
/*   Updated: 2021/10/19 12:40:38 by adrian           ###   ########.fr       */
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
  template <class T1, class T2>
  struct pair {
    typedef T1   first_type;
    typedef T2   second_type;

    pair() : first(), second() {};
    pair (const first_type &a, const second_type &b) : first(a), second(b) {};

    template<class U, class V>
    pair (const pair<U, V> &pr) : first(pr.first), second(pr.second) {};

    ~pair() {};

    pair<T1, T2>  &operator= (const pair<T1, T2> &pr) {
      first = pr.first;
      second = pr.second;
      return *this;
    };

    first_type  first;
    second_type second;
  };

	template <class T1, class T2>
  	ft::pair<T1,T2> make_pair (T1 x, T2 y) {
	  return ft::pair<T1, T2>(x, y);
  }
};

#endif