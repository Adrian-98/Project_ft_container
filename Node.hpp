/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:24:10 by adrian            #+#    #+#             */
/*   Updated: 2021/05/07 15:58:14 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

# include <limits>


template <typename T>
class Node
{
	private:
			T	 	value;
			Node<T>	*prev;
			Node<T>	*next;
	public:
			Node() : prev(nullptr), next(nullptr){}
			Node(const T& value) : next(nullptr), prev(nullptr), value(value) {}
			
			Node(Node const &copy) : prev(copy.prev), next(copy.next), value(copy.value){}
			Node &operator=(Node const &copy)
			{
				this->prev = copy.prev;
				this->next = copy.next;
				this->valu = copy.value;
				return (*this);
			}
			
			virtual ~Node(){}
			
			Node *getPrev(void){
				return (this->prev);
			}
			Node *getNext(void){
				return (this->next);
			}
			Node getValue(void){
				return (this->value);
			}
			void setPrev(Node *prev){
				this->prev = prev;
			}
			void setNext(Node *next){
				this->next = next;
			}
			void setValue(T &value){
				this->value = value;
			}
			Node *clone_whit_value(void){
				return (new Node(NULL, NULL, this->value));
			}
			void disconnect(void) {
				if (this->prev)
					this->prev->next = this->next;
				if (this->next)
					this->next->prev = this->prev;
			}

			void insert_before(Node *node) {
				if (this->prev){
					node->prev = this->prev;
					this->prev->next = node;
				}
				node->next = this;
				this->prev = node;
			}
			void insert_after(Node *node) {
				if (this->next){
					node->next = this->next;
					this->next->prev = node;
				}
				node->prev = this;
				this->next = node;
			}
};

#endif
