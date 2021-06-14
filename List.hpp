/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:34:41 by adrian            #+#    #+#             */
/*   Updated: 2021/06/14 14:15:13 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

# include "Node.hpp"
# include "ListIterators.hpp"
# include "Algorithm.hpp"

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
			typedef ListIterator<value_type> iterator;
			typedef ListIterator<value_type> const_iterator;
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
					this->erase(begin(), end());
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
					return (this->head->getvalue());
				}
				
				reference back() {
					return (this->tail->getvalue());
				}
				
				const_reference back() const {
					return (this->tail->getvalue());
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
					if (this->size_ > 0)
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
					return (iterator(this->tail));
				}
				const_iterator end() const{
					return (const_iterator(this->tail));
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
					node_pointer next = position.getnode()->getnext();
					position.getnode()->disconnect();
					delete position.getnode();
					--this->size_;
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
				
				template <typename Predicate>
				void remove_if (Predicate pred){
					iterator first = this->begin();
					iterator last = this->end();

					while (first != last)
					{
						if (*pred == *first)
							first = erase(first);
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

				void unique(){
					iterator first = this->begin();
					iterator last = this->end();
					
					while (first != last)
					{
						while (*first == first.getnode()->getnext()->getvalue())
							first = erase(first); 
						if (first != NULL)
							first++;
					}
				}
				
				template <class BinaryPredicate>
  				void unique (BinaryPredicate binary_pred){
					iterator first = this->begin();
					iterator last = this->end();
					
					while (first != last)
					{
						if (binary_pred(*first, first.getnode()->getnext()->getvalue()))
							erase(first);
						if (first != NULL)
							first++;
					}
				}
				
				void merge (List& x){
					if (&x == this)
						return ;
					if (this->size_ == 0) {
						this->assign(x.begin(), x.end());
						x.clear();
						return ;
					}
					iterator first = x.begin();
					iterator last = x.end();
					iterator position = this->end();
					insert(++position, first, last);
					x.clear();
				}

				template <class Compare>
 				void merge (List& x, Compare comp){
					 if (&x == this)
						return ;
					if (this->size_ == 0) {
						this->assign(x.begin(), x.end());
						x.clear();
						return ;
					}
					iterator f1 = this->begin();
					iterator e1 = this->end();
					iterator f2 = x.begin();
					iterator e2 = x.end();

					while (f1 != e1 && f2 != e2) {
						if ((*comp)(*f2, *f1)) {
							x.m_begin = f2.as_node()->next();
							--x.m_size;
							f2.as_node()->disconnect();
							f1.as_node()->insert_before(f2.as_node());
							if (f1 == this->begin())
								this->m_begin = this->m_begin->previous();
							++this->m_size;
							f2 = x.begin();
						} else
							++f1;
					}
					this->splice(e1, x);
				}
				
				void sort(void) {
					if (this->m_size <= 1)
						return ;
					this->sort(&less_than<value_type>);
				}
				
				template <class Compare>
				void sort(Compare comp){
					if (size_ <= 1)
						return ;
					value_type tmp;
					iterator first = this->begin();
					iterator last = this->end();
					iterator next;	
					
					while (first != last)
					{
						next = first;
						while (++next != last)
						{
							if((*comp)(*next, *first))
							{
								tmp = *next;
								*next = *first;
								*first = tmp;
							}
						}
						first++;
					}
				}

				void reverse(){
					if (size_ <= 1)
						return ;
					iterator first = this->begin();
					iterator last = this->end();
					List tmp;
					while (first != last)
						tmp.popFront(first++);
					first = tmp.begin();
					last = tmp.end();
					this->clear();
					this->insert(this->begin(), first, last);
				}
				
  				void swap (List<T>& x, List<T>& y){
					x.swap(y);	  
				}
};

				template<typename value_type>
				bool operator==(List<value_type> const &lhs, List<value_type> const &rhs) {
					if (lhs.size() != rhs.size())
						return (false);
					typename List<value_type>::const_iterator first1 = lhs.begin();
					typename List<value_type>::const_iterator last1 = lhs.end();
					typename List<value_type>::const_iterator first2 = rhs.begin();
					typename List<value_type>::const_iterator last2 = rhs.end();
					while (first1 != last1)
						if (*first1++ != *first2++)
							return (false);
					return (true);
				}

				template<typename T>
				bool operator!=(List<T> const &lhs, List<T> const &rhs) {
					return (!(lhs == rhs));
				}

				template<typename T>
				bool operator<(List<T> const &lhs, List<T> const &rhs) {
					return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
				}

				template<typename T>
				bool operator<=(List<T> const &lhs, List<T> const &rhs) {
					return (!(rhs < lhs));
				}

				template<typename T>
				bool operator>(List<T> const &lhs, List<T> const &rhs) {
					return (rhs < lhs);
				}

				template<typename T>
				bool operator>=(List<T> const &lhs, List<T> const &rhs) {
					return (!(lhs < rhs));
				}




#endif