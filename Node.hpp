/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:24:10 by adrian            #+#    #+#             */
/*   Updated: 2021/04/29 12:08:38 by amunoz-p         ###   ########.fr       */
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
			Node setPrev(Node *prev){
				this->prev = prev;
			}
			Node setNext(Node *next){
				this->next = next;
			}
			Node setValue(T &value){
				this->value = value;
			}
			Node *clone_whit_value(void){
				return (new Node(NULL, NULL, this->value));
			}
};

#endif
