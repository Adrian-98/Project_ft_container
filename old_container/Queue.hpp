/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 18:44:15 by adrian            #+#    #+#             */
/*   Updated: 2021/06/23 19:50:46 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
#define QUEUE_HPP
# include "List.hpp"

template<typename T, typename K = List<T> >
class Queue
{
	public:
			typedef size_t size_type;
			typedef T value_type;
			typedef K container_type;
			typedef T* pointer;
			typedef T const * const_pointer;
			typedef T& reference;
			typedef T const & const_reference;
	
	protected:
				container_type container;
	
	public:
		Queue(container_type const &container=container_type()): conatiner(container)
		Queue(Queue<T, K> const &other): container(other.container) {}
		
		virtual ~Queue() {}
		
		Queue &operator=(Queue const &other) {
			this->container = other.container;
			return (*this);
		}

		bool empty() const{
			return(this->container.empty());
		}

		size_type size() const{
			return (this->container.size());
		}

		reference front(){
			return (this->container.front())
		}

		const_reference front(void) const {
			return (this->container.front());
		}

		reference back(void) {
			return (this->container.back());
		}
		
		const_reference back(void) const {
			return (this->container.back());
		}

		void pop(){
			this->container.pop_front();
		}

		void push(const_reference val) {
			this->container.push_back(val);
		}

		template<typename queue_type, typename container_type>
		friend bool operator==(Queue<queue_type, container_type> const &lhs, Queue<queue_type, container_type> const &rhs) {
			return (lhs.container == rhs.container);
		}

		template<typename queue_type, typename container_type>
		friend bool operator!=(Queue<queue_type, container_type> const &lhs, Queue<queue_type, container_type> const &rhs) {
			return (lhs.container != rhs.container);
		}

		template<typename queue_type, typename container_type>
		friend bool operator<(Queue<queue_type, container_type> const &lhs, Queue<queue_type, container_type> const &rhs) {
			return (lhs.container < rhs.container);
		}

		template<typename queue_type, typename container_type>
		friend bool operator<=(Queue<queue_type, container_type> const &lhs, Queue<queue_type, container_type> const &rhs) {
			return (lhs.container <= rhs.container);
		}

		template<typename queue_type, typename container_type>
		friend bool operator>(Queue<queue_type, container_type> const &lhs, Queue<queue_type, container_type> const &rhs) {
			return (lhs.container > rhs.container);
		}

		template<typename queue_type, typename container_type>
		friend bool operator>=(Queue<queue_type, container_type> const &lhs, Queue<queue_type, container_type> const &rhs) {
			return (lhs.container >= rhs.container);
		}
};




#endif