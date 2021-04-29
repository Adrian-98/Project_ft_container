/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:34:41 by adrian            #+#    #+#             */
/*   Updated: 2021/04/29 11:42:46 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

# include "Node.hpp"
# include "ListIterators.hpp"

template<typename T>
class List
{
		public: 
			typedef std::ptrdiff_t difference_type;
			typedef unsigned long size_type;
			typedef T value_type;
			typedef Node<value_type> node_type;
			typedef node_type* node_pointer;
			typedef value_type* pointer;
			typedef value_type const *const_pointer;
			typedef value_type& reference;
			typedef value_type const &const_reference;
			typedef ListIterator<value_type, node_type> iterator;
			typedef ListIterator<value_type const, node_type const> const_iterator;
			typedef ReverseIterator<iterator> reverse_iterator;
			typedef ReverseIterator<const_iterator> const_reverse_iterator;
		private:
				node_pointer head;
				node_pointer tail;

				size_type	n_nodes;
			
		
}



#endif