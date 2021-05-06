/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:34:41 by adrian            #+#    #+#             */
/*   Updated: 2021/05/06 17:45:04 by adrian           ###   ########.fr       */
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
			typedef ListIterator<node_pointer> iterator;
			typedef ListIterator<const_pointer> const_iterator;
			typedef ListReverseIterator<iterator> reverse_iterator;
			typedef ListReverseIterator<const_iterator> const_reverse_iterator;
		private:
				node_pointer head;
				node_pointer tail;

				size_type	size_;
			
		public:
				List(): head(NULL), tail(NULL), size_(0){
					tail = new Node<value_type>();
					head = tail;
					tail->setPrev = NULL;
					tail->setNext = NULL;
				}
				
				List(const List<T> &copy): head(copy.head), tail(copy.tail), size_(copy.size_){}
				List  &operator=(List const &copy)
				{
					this->head = copy.head;
					this->tail = copy.tail;
					this->size_ = copy.size_;
					return (*this);
				}		
				~List(){
					clear();
					delete tail;
				}
				
				int size() const { return size_; }

				bool empty() const { return !head; }
			
				reference front()
				{
					if (!head)
						return (0);
					else
						return (head->value);
				}

				reference back()
				{
					if (!tail)
						return (0);
					else 
						return tail->value;
				}

				void clear()
				{
					while (head){
      					popBack();
					}
   				}

				void pushFront(const_reference newData)
				{
					node_pointer newNode = new node_type(newData);
					if (!head)
					{
						head = newNode;
						tail = newNode;
					}
					else
					{
						node_pointer oldHead = head;
						head->setPrev(newNode);
						newNode->setNext(oldHead);
						head = newNode;
					}
					size_++;
				}

				void pushBack(const_reference newData)
				{
					node_pointer newNode = new node_type(newData);
					if (!head)
					{
						head = newNode;
						tail = newNode;
					}
					else
					{
						node_pointer oldTail = tail;
						tail->setNext(newNode);
						tail->setPrev(oldTail);
						tail = newNode;
					}
					size_++;
				}

				void popFront()
				{
					if (!head)
						return;
					if (!head->next){
						delete head;
						head = nullptr;
						tail = nullptr;
						size_--;
						return ;
					}
					node_pointer oldHead = head;
					head = head->next;
					head->prev = nullptr;
					delete oldHead;
					oldHead = nullptr;
					size_--;
				}

				void popBack(){
					if (!head)
						return;
					if (!tail->prev){
						popFront();
						return;	
					}
					node_pointer oldTail = tail;
					tail = tail->prev;
					tail->next = nullptr;
					delete oldTail;
					oldTail = nullptr;
					size_--; 				
				}
				
				void assing(iterator first, iterator last)
				{
					this->clear();
					while (first != last)
						this->pushBack(*first++);
				}
				
				void assign(size_type size, const_reference val)
				{
					this->clear();
					for (size_type i = 0; i < size; i++)
						this->pushBack(val);
				}
};



#endif