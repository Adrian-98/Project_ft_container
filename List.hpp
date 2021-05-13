/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:34:41 by adrian            #+#    #+#             */
/*   Updated: 2021/05/13 12:47:45 by amunoz-p         ###   ########.fr       */
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
					tail->setPrev(NULL); 
					tail->setNext(NULL);
				}
				
				List(const List<T> &copy): head(copy.head), tail(copy.tail), size_(copy.size_){}
				List  &operator=(List const &copy)
				{
					this->head = copy.head;
					this->tail = copy.tail;
					this->size_ = copy.size_;
					return (*this);
				}
				void clear()
				{
					while (head){
      					this->popBack();
					}
					this->head = this->tail;
					this->tail->setPrev(nullptr);
					this->tail->setNext(nullptr);
   				}		
				
				int size() const { return size_; }

				bool empty() const { return !head; }
			
				reference front() {
					return (this->head->getvalue());
				}
				
				const_reference front() const {
					return (this->head->value());
				}
				
				reference back() {
					return (this->tail->getvalue());
				}
				
				const_reference back() const {
					return (this->tail->value());
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
					if (!head->getnext()){
						delete head;
						head = nullptr;
						tail = nullptr;
						size_--;
						return ;
					}
					node_pointer oldHead = head;
					head = head->getnext();
					head->setPrev(nullptr);
					delete oldHead;
					oldHead = nullptr;
					size_--;
				}

				void popBack(){
					if (!head)
						return;
					if (!tail->getprev()){
						popFront();
						return;	
					}
					node_pointer oldTail = tail;
					tail = tail->getprev();
					tail->setNext(nullptr);
					delete oldTail;
					oldTail = nullptr;
					size_--; 				
				}
				~List(){
					clear();
					delete tail;
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
				iterator begin(){
					return (iterator(this->head));
				}
				
				const_iterator begin() const{
					return (const_iterator(this->head));
				}
				reverse_iterator rbegin(void) {
					return (reverse_iterator(this->end()));
				}
				
				const_reverse_iterator rbegin(void) const {
					return (const_reverse_iterator(this->end()));
				}
				
				iterator end(){
					return (iterator(this->tail->getNext()));
				}
				const_iterator end() const{
					return (const_iterator(this->tail->getNext()));
				}
				reverse_iterator rend(void) {
					return (reverse_iterator(this->begin()));
				}
				const_reverse_iterator rend(void) const {
					return (const_reverse_iterator(this->begin()));
				}
				
				iterator erase(iterator position){
					if (position == head){
						this->popFront();
						return (this->begin());
					}else if (position == tail){
						this->popBack();
						return (this->end());
					}
					node_pointer next = position.getnode()->next();
					position.getnode().disconnect();
					delete position.getnode();
					--this->m_size;
					return (iterator(next));	
				}
				iterator erase(iterator first, iterator last){
					while (first != last)
						this->erase(first++);
					return (first);
				}
				
				iterator insert(iterator position, const_reference val){
					if (position == this->begin()) {
						this->push_front(val);
						return (this->begin());
					} else if (position == this->end()) {
						this->push_back(val);
						return (this->end());
					}
					node_pointer newNode = new node_type(val);
					position.getnode()->insert_before(newNode);
					this->size_++;
					return (iterator(newNode));
				}

				void insert (iterator position, size_type n, const_reference val){
					for (size_type i = 0; i < n; i++)
						this->insert(position, val);
				}

				void insert (iterator position, iterator first, iterator last){
					while (first != last)
					{
						this->insert(position, *first++);
					}
				}
				size_type max_size(void) const{
					return (std::numeric_limits<difference_type>::max() / sizeof(value_type));
				}
				
				void resize(size_type n, value_type val=value_type()) {
					if (n == 0)
						this->clear();
					if (n < this->size_)
					{
						iterator first = this->begin();
						size_type i = 0;
						while (i < n){
							i++;
							first++;
						}
						this->erase(first, this->end());
					}
					else{
						this->insert(this->end(), n - this->size_, val);
					}
				}
				
				void splice (iterator position, List &x){
					splice(position, x, x.begin(), x.end());
				}

				void splice (iterator position, List& x, iterator i){
					iterator next = i;
					this->splice(position, x, i, ++next);
				}
				
				void splice (iterator position, List& x, iterator first, iterator last){
					insert(position, first, last);
					while (first != last)
						x.erase(first++);
				}

				void remove (const value_type& val){
					iterator first = this->begin();
					iterator last = this->end();
					while (first != last)
					{
						if (*first == val)
							first = this->erase(first);
						else
							first++;
					}					
				}
				
				void swap (List& x){
					List tmp;
					tmp.assign(begin(), end());
					if (x.size_ == 0)
						this->clear();
					else
						this->assign(x.begin(), x.end());
					x.assign(tmp.begin(), tmp.end());
				}
};



#endif