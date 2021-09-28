/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:42:14 by amunoz-p          #+#    #+#             */
/*   Updated: 2021/09/28 16:52:20 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "MapIterator.hpp"




template <class Key>
		struct less : std::binary_function <Key,Key,bool> {
			bool operator() (const Key & x, const Key & y) const {
				return (x < y);
			}
		};




#endif
