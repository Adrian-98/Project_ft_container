/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:42:14 by amunoz-p          #+#    #+#             */
/*   Updated: 2021/09/29 16:57:42 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "MapIterator.hpp"
#include "Node.hpp"
#include "Avl.hpp"

template <typename Key, typename T, class Alloc, class Compare = ft::less<Key> >
		   

class Map{
		private:
			typedef typename Alloc::template rebind<Node<ft::pair<Key, T> > >::other Tree_allocator_type;
			
			Avl<Key, T, Alloc, Compare> *_storage;
			Tree_allocator_type 		_tree_alloc;

		public:
		
			typedef	Key										key_type;
			typedef T										mapped_type;
			typedef	ft::pair<const key_type, mapped_type>		value_type;
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
			
			Map(const map& x)
			{
				iterator it = x.begin();
				_tree_alloc = Tree_allocator_type();
				_storage = _tree_alloc.allocate(1);
				_tree_alloc.construct(_storage);
				while (it != src.end())
				{
					_storage->add((*it).first, (*it).second);
					it++;
				}
			}

			~Map(){
				_tree_alloc.destroy(_storage);
				_tree_alloc.deallocate(_storage, 1);
			}

			Map	&operator=(const map &x) {
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

			
};





#endif
