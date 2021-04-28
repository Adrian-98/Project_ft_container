/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListIterators.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 12:29:58 by adrian            #+#    #+#             */
/*   Updated: 2021/04/28 13:34:25 by adrian           ###   ########.fr       */
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
			ListIterator(const listIterator<T>& origin) : now(origin.now){}
			ListIterator<T>& operator=(const listIterator<T>& origin)
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

			bool		  operator==(const listIterator<T> &origin) const
			{
				return (now == origin.now);
			}

			bool		  operator==(const listConstIterator<T> &origin) const
			{
				return (now == origin.getnode());
			}

			bool		  operator!=(const listIterator<T> &origin) const
			{
				return (!operator==(origin));
			}

			bool		  operator!=(const listConstIterator<T> &origin) const
			{
				return (!operator==(origin));
			}
			
			node<T>*		getnode(void) const
			{
				return (this->now);
			}
};

template <typename T>
class ListReverseIterator
{
	private	:
		Node<T> *now;
	public	:
		ListReverseIterator(): now(NULL){}
		ListReverseIterator(node<T> *now) : now(now){}

		ListReverseIterator(const ListReverseIterator<T>& origin) : now(origin.now){}

		ListReverseIterator(const listIterator<T>& origin) : now(origin.getnode()->getPrev()){}

		ListReverseIterator<T>& operator=(const ListReverseIterator<T>& origin)
		{
			this->now = origin.now;
			return (*this);
		}

		ListReverseIterator<T>& operator=(const listIterator<T>& origin)
		{
			this->now = origin.getnode()->getPrev();
			return (*this);
		}

		~ListReverseIterator()
		{
			
		}

		T& operator*()
		{
			return (now->getValue());
		}

		ListReverseIterator<T>& operator++()
		{
			this->now = this->now->getPrev();
			return (*this);
		}

		ListReverseIterator<T> operator++(int)
		{
			ListReverseIterator<T> temp(*this);
			now = now->getPrev();
			return (temp);
		}

		ListReverseIterator<T>& operator--()
		{
			this->now = this->now->getNext();
			return (*this);
		}

		ListReverseIterator<T> operator--(int)
		{
			ListReverseIterator<T> temp(*this);
			now = now->getNext();
			return (temp);
		}

		T*			  operator->()
		{
			return &(operator*());
		}

		bool		  operator==(const ListReverseIterator<T> &origin) const
		{
			return (now == origin.now);
		}

		bool		  operator==(const listReverseConstIterator<T> &origin) const
		{
			return (now == origin.getnode());
		}

		bool		  operator!=(const ListReverseIterator<T> &origin) const
		{
			return (!operator==(origin));
		}

		bool		  operator!=(const listReverseConstIterator<T> &origin) const
		{
			return (!operator==(origin));
		}

		node<T>*		getnode(void) const
		{
			return (this->now);
		}

		listIterator<T>		base(void)
		{
			return (listIterator<T>(now->getNext()));
		}
};

#endif