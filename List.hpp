/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:34:41 by adrian            #+#    #+#             */
/*   Updated: 2021/04/29 12:13:38 by amunoz-p         ###   ########.fr       */
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
			
		public:
				List(): head(NULL), tail(NULL), n_nodes(0){}
				List(const List<T> &copy): head(copy.head), tail(copy.tail), n_nodes(copy.n_nodes){}
				List  &operator=(List const &copy)
				{
					this->head = copy.head;
					this->tail = copy.tail;
					this->n_nodes = copy.n_nodes;
					return (*this);
				}		
				~List(){
					clear();
				}
// Returns the size of the list.
				int size() const { return n_nodes; }
// Returns true if the list is empty.
				bool empty() const { return !head; }
//Returns a reference to the actual front data item in the list.			
				reference front()
				{
					if (!head)
						throw std::runtime_error("front() called on empty LinkedList");
					else 
						return head->value;
				}
//Returns a reference to the actual last data item in the list.	
				reference back()
				{
					if (!tail)
						throw std::runtime_error("front() called on empty LinkedList");
					else 
						return tail->value;
				}
// Delete all items in the list, leaving it empty.
				void clear() {
				while (head) {
      				popBack();
   				}			
};



#endif