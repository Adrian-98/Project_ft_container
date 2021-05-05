/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListIterators.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 12:29:58 by adrian            #+#    #+#             */
/*   Updated: 2021/05/05 11:36:21 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTITERATOR_HPP
#define LISTITERATOR_HPP

#include "Node.hpp"

template <typename T>
class ListIterator{
	private:
			Node<T> *now;
	public:
			ListIterator(): now(NULL){}
			ListIterator(Node <T> *now): now(now){}
			ListIterator(const ListIterator<T>& origin) : now(origin.now){}
			ListIterator<T>& operator=(const ListIterator<T>& origin)
			{
				this->now = origin.now;
				return (*this);
			}

			~ListIterator(){}

			T& operator*()
			{
				return (now->getValue());
			}
			ListIterator<T>& operator++()
			{
				this->now = this->now->getNext();
				return (*this);
			}
			ListIterator<T> operator++(int)
			{
				ListIterator<T> temp(*this);
				now = now->getNext();
				return (temp);
			}
			ListIterator<T> &operator--()
			{
				this->now = this->now->getPrev();
				return (*this);	
			}
			ListIterator<T> operator--(int)
			{
				ListIterator<T> temp(*this);
				now = now->getPrev();
				return (temp);
			}
			T*			  operator->()
			{
				return &(operator*());
			}

			bool		  operator==(const ListIterator<T> &origin) const
			{
				return (now == origin.now);
			}

			bool		  operator!=(const ListIterator<T> &origin) const
			{
				return (!operator==(origin));
			}
			
			Node<T>*		getnode(void) const
			{
				return (this->now);
			}
};

template <typename It>
class ListReverseIterator: public It
{
	public:
		using typename It::value_type;
		using typename It::pointer;
		using typename It::const_pointer;
		using typename It::reference;
		using typename It::const_reference;
		using typename It::difference_type;
	
	public	:
		ListReverseIterator(): It(){}
		ListReverseIterator(It const &it) : It(it){}

		ListReverseIterator(ListReverseIterator const &other) : It(other.now){}

		ListReverseIterator<T>& operator=(ListReverseIterator const &other)
		{
			this->now = other.now;
			return (*this);
		}

		~ListReverseIterator()
		{
			
		}

		reference operator*()
		{
			It tmp(*this)
			return (*--tmp;)
		}

		const_reference operator*() const {
			It tmp(*this);
			return (*--tmp);
		}
		pointer operator->() {
			It tmp(*this);
			return (&*--tmp);
		}
		const_pointer operator->() const {
			It tmp(*this);
			return (&*--tmp);
		}
		ReverseIterator operator++(int) {
			ReverseIterator tmp(*this);
			operator++();
			return (tmp);
		}
		It &operator++() {
			return (this->It::operator--());
		}
		ReverseIterator operator--(int) {
			ReverseIterator tmp(*this);
			operator--();
			return (tmp);
		}
		It &operator--() {
			return (this->It::operator++());
		}
};

#endif