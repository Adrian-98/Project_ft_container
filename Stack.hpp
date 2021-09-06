/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:53:25 by adrian            #+#    #+#             */
/*   Updated: 2021/09/06 13:45:27 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP
# include "List.hpp"


template<typename T, typename K = List<T> >
class Stack
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
	Stack(container_type const &container=container_type()): container(container) {}
	Stack(Stack const &other): container(other.container) {}
	virtual ~Stack() {}

	Stack &operator=(Stack const &other) {
		this->container = other.container;
		return (*this);
	}

	bool empty(void) const {
		return (this->container.empty());
	}
	size_t size(void) const {
		return (this->container.size());
	}

	reference top(void) {
		return (this->container.back());
	}
	const_reference top(void) const {
		return (this->container.back());
	}

	void push(const_reference val) {
		this->container.pushBack(val);
	}
	void pop(void) {
		this->container.popBack();
	}

	template<typename stack_type, typename container_type>
	friend bool operator==(Stack<stack_type, container_type> const &lhs, Stack<stack_type, container_type> const &rhs) {
		return (lhs.container == rhs.container);
	}

	template<typename stack_type, typename container_type>
	friend bool operator!=(Stack<stack_type, container_type> const &lhs, Stack<stack_type, container_type> const &rhs) {
		return (lhs.container != rhs.container);
	}

	template<typename stack_type, typename container_type>
	friend bool operator<(Stack<stack_type, container_type> const &lhs, Stack<stack_type, container_type> const &rhs) {
		return (lhs.container < rhs.container);
	}

	template<typename stack_type, typename container_type>
	friend bool operator<=(Stack<stack_type, container_type> const &lhs, Stack<stack_type, container_type> const &rhs) {
		return (lhs.container <= rhs.container);
	}

	template<typename stack_type, typename container_type>
	friend bool operator>(Stack<stack_type, container_type> const &lhs, Stack<stack_type, container_type> const &rhs) {
		return (lhs.container > rhs.container);
	}

	template<typename stack_type, typename container_type>
	friend bool operator>=(Stack<stack_type, container_type> const &lhs, Stack<stack_type, container_type> const &rhs) {
		return (lhs.container >= rhs.container);
	}
};


#endif
