/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:42:14 by amunoz-p          #+#    #+#             */
/*   Updated: 2021/10/04 18:51:08 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "MapIterator.hpp"
#include "Node.hpp"
#include "Avl.hpp"
#include <cstddef>
#include <limits.h>
#include <stdexcept>
#include "MapIterator.hpp"
#include <memory>

template <typename Key, typename T, class Compare = ft::less<Key>, class Alloc = std::allocator<std::pair<Key, T> > >
		   

class Map{
		private:
			typedef typename Alloc::template rebind<Avl<Key, T, Compare, Alloc> >::other Tree_allocator_type;
			
			Avl<Key, T, Compare, Alloc> *_storage;
			Tree_allocator_type 		_tree_alloc;

		public:
			
			typedef	Key										key_type;
			typedef T										Mapped_type;
			typedef	ft::pair<const key_type, Mapped_type>		value_type;
			typedef	Compare									key_compare;
			typedef value_type&								reference;
			typedef const value_type&						const_reference;
			typedef value_type*								pointer;
			typedef const value_type*						const_pointer;
			typedef MapIterator<Key, T>						iterator;
			typedef typename Alloc::size_type				size_type;
			typedef const iterator							const_iterator;
			typedef MapReverseIterator<Key, T>				reverse_iterator;
			typedef const reverse_iterator					const_reverse_iterator;
			typedef std::ptrdiff_t							difference_type;
			typedef Alloc									allocator_type;
			
			
			explicit Map(const key_compare& comp = key_compare()){
				_tree_alloc = Tree_allocator_type();
				_storage = _tree_alloc.allocate(1);
				_tree_alloc.construct(_storage);
			}

			template <class InputIterator>
			Map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){
				_tree_alloc = Tree_allocator_type();
				_storage = _tree_alloc.allocate(1);
				_tree_alloc.construct(_storage);
				while (first != last)
				{
					_storage->add((*first).first, ((*first).second));
					first++;
				}
			}
			
			Map(const Map& x)
			{
				iterator it = x.begin();
				_tree_alloc = Tree_allocator_type();
				_storage = _tree_alloc.allocate(1);
				_tree_alloc.construct(_storage);
				while (it != x.end())
				{
					_storage->add((*it).first, (*it).second);
					it++;
				}
			}

			~Map(){
				_tree_alloc.destroy(_storage);
				_tree_alloc.deallocate(_storage, 1);
			}

			Map	&operator=(const Map &x) {
				_tree_alloc.destroy(_storage);
				_tree_alloc.deallocate(_storage, 1);
				Map::iterator it = x.begin();
				_tree_alloc.allocate(1);
				_tree_alloc.construct(_storage);
				while (it != x.end()){
					_storage->add((*it).first, (*it).second);
					it++;
				}
				return *this;
			}

			bool  empty() const{
				return (_storage->size == 0);
			}
			
			size_type	size() const {
				return (_storage->size);
			}
		
			size_type	max_size() const {
				return (allocator_type().max_size()/5);
			}

			Mapped_type &operator[] (const key_type& k) {
				if (count(k) == 0)
					_storage->add(k, T());					//PARRENTESIS EN  LA T?¿
				Node<ft::pair<Key, T> > *node = _storage->find(k);
				return node->data.second;
			}	

			size_type count (const key_type& k) const {
				Node<ft::pair<Key, T> > *node = _storage->find(k);
				if (node == NULL)
					return 0;
				return 1;
			}

			iterator insert (iterator position, const value_type& val){
				_storage->add(val.first, val.second, get_node(position));
				return insert(val).first;
			}

			ft::pair<iterator,bool>			insert(const value_type& val) {
				Node<ft::pair<Key, T> > * nd = _storage->find(val.first);
				if (nd != NULL) {
					ft::pair<iterator,bool> pr = ft::make_pair(iterator(nd), false);
					return pr;
				}
				nd = _storage->add(val.first, val.second);
				iterator it = iterator(nd);
				ft::pair<iterator,bool> pr = ft::make_pair(it, true);
				return pr;
			}

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last) {
				while (first != last)
				{
					value_type val = value_type((*first).first, (*first).second);
					insert(val);
					first++;
				}
			}

			void	erase(iterator position){
				_storage->remove(get_node(position));
			}

			size_type erase(const key_type& k){
				Node<ft::pair<Key, T> > * node = _storage->find(k);
				if (!node)
					return 0;
				_storage->remove(node);
				return 1;	
			}

			void	erase(iterator first, iterator last){
				while (first != last){
					Node<ft::pair<Key, T> > * node = get_node(first);
					first++;
					_storage->remove(node);
				}
			}

			void	swap (Map& x) {
				Avl<Key, T, Alloc, Compare> * tmp = _storage;
				_storage = x._storage;
				x._storage = tmp;
			}

			
			void	clear() {
				Map::iterator it = begin();
				while (it != end()) {
					Node<ft::pair<Key, T> > *node = get_node(it);
					it++;
					_storage->remove(node);
				}
			}

			key_compare key_comp() const{
				return Compare();
			}

			class value_compare
			{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
				friend class Map;
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {}  // constructed with Map's comparison object
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};

			value_compare value_comp() const{
				return (value_compare(Compare()));
			}

			
			iterator lower_bound (const key_type& k){
				Map::iterator it = begin();
				while (it != end() && !key_compare()(k, (*it).first))
					it++;
				return it;
			}
			
			const_iterator lower_bound (const key_type& k) const {
				Map::const_iterator it = begin();
				while (it != end() && !key_compare()(k, (*it).first))
					it++;
				return (it);
			}

			iterator upper_bound(const key_type& k) {
				Map::iterator it = begin();
				while (it != end() && !key_compare()(k, (*it).first))
					it++;
				return (it);
			}

			const_iterator upper_bound(const key_type& k) const{
				Map::const_iterator it = begin();
				while (it != end() && !key_compare()(k, (*it).first))
					it++;
				return (it);
			}
			
			//find
			iterator find (const key_type& k) {
				Node<ft::pair<Key, T> > *node = _storage->find(k);
				if (node == NULL)
					return end();
				return iterator(node);
			}

			const_iterator find (const key_type& k) const {
				Node<ft::pair<Key, T> > *node = _storage->find(k);
				if (node == NULL)
					return end();
				return const_iterator(node);
			}
			

			ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
				ft::pair<const_iterator, const_iterator> pair(lower_bound(k), upper_bound(k));
				return pair;
			}

			ft::pair<iterator,iterator>             equal_range (const key_type& k) {
				ft::pair<iterator, iterator> pair(lower_bound(k), upper_bound(k));
				return pair;
			}

			iterator 			begin(){
				return (iterator(_storage->get_begin()));
			}
			
			const_iterator		begin() const {
				return (const_iterator(_storage->get_begin()));
			}

			iterator				end() {
				return (iterator(_storage->get_end()));
			}

			const_iterator			end() const {
				return (const_iterator(_storage->get_end()));
			}

			reverse_iterator		rbegin() {
				return (reverse_iterator(_storage->get_rbegin()));
			}

			const_reverse_iterator	rbegin() const {
				return (const_reverse_iterator(_storage->get_rbegin()));
			}

			reverse_iterator		rend() {
				return (reverse_iterator(_storage->get_rend()));
			}

			const_reverse_iterator	rend() const {
				return (const_reverse_iterator(_storage->get_rend()));
			}

			Node<ft::pair<Key, T> > *get_node(iterator it) {
				return (_storage->find((*it).first));
			}				
};

		template <typename Key,typename T, class Alloc>
		void swap(Map<Key,T, Alloc> & x, Map<Key,T, Alloc> & y) {
			x.swap(y);
		}



#endif
