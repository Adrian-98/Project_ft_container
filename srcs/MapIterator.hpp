/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 16:03:50 by amunoz-p          #+#    #+#             */
/*   Updated: 2021/10/04 13:31:45 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITERATOR_HPP
#define MAPITERATOR_HPP

#include "Node.hpp"
#include <iterator>
#include "Pair.hpp"

typedef size_t size_type;
template <typename Key, typename Value>

class MapIterator : public std::iterator<std::input_iterator_tag, Key, Value>
{
    private:
            Node<ft::pair<Key, Value> > *p;
    public:
    
            MapIterator(Node<ft::pair<Key, Value> > *it): p(it){}
            MapIterator(const MapIterator &mit) : p(mit.p){}
            
            MapIterator &operator++(){
                if (p){
                    if (p->right){
                        p = p->right;
                        while (p->left)
                            p = p->left;
                        
                    }
                    else{
                        while (p->parent && p == p->parent->right)
                            p = p->parent;
                        p = p->parent;
                    }
                }
                return *this;
            }
            
            template <class Y>
            MapIterator &operator++(Y){
                MapIterator ret(*this);
                operator++();
                return ret;
            }
            
            MapIterator operator+(size_t n){
                MapIterator it(*this);
                while (n > 0){
                    it++;
                    n--;
                }
                while (n < 0){
                    it--;
                    n++;
                }
                return it;
            }

            MapIterator &operator--(){
                if (p){
                    if (p->left){
                        p = p->left;
                        while (p->right)
                            p = p->right;
                    }
                    else{
                        while (p->parent && p->parent->left)
                            p = p->parent;
                        p = p->parent;
                    }
                }
                return *this;
            }

            template <class Y>
			MapIterator operator--(Y) {
				MapIterator it(*this);
				operator--();
				return it;
			}

            MapIterator operator-(size_t n){
                MapIterator it(*this);
                while (n > 0){
                    n--;
                    it--;
                }
                while (n < 0){
                    n++;
                    it++;
                }
                return it;
            }

            bool operator==(const MapIterator & rhs) const {
			return p==rhs.p;
            }
            bool operator!=(const MapIterator & rhs) const {
                return p!=rhs.p;
            }
		
            ft::pair<Key, Value> & operator*() {
                return p->data;
            }
};

template <typename Key, typename Value>
class MapReverseIterator : public std::iterator<std::input_iterator_tag, Key, Value>
{
	private:
    		Node<ft::pair<Key, Value> > *p;
            
	public:

		MapReverseIterator(Node<ft::pair<Key, Value> > * e) : p(e) {}
		MapReverseIterator(const MapReverseIterator & mit) : p(mit.p) {}
		MapReverseIterator & operator++() {
			if (p) {
				if (p->left) {
					p = p->left;
					while (p->right)
						p = p->right;
				}
				else { 
					while (p->parent && p == p->parent->left)
						p = p->parent;
					p = p->parent;
				}
			}
			return *this;
		}

		template <class Y>
			MapReverseIterator operator++(Y) {
				MapReverseIterator it(*this);
				operator++();
				return it;
			}

		MapReverseIterator operator+(size_type n)
		{
			MapReverseIterator it(*this);	
			while (n > 0)
			{
				it++;
				n--;
			}
			while (n < 0)
			{
				it--;
				n++;
			}
			return (*this);
		}


		MapReverseIterator & operator--() {
			if (p) {
				if (p->right) {
					p = p->right;
					while (p->left)
						p = p->left;
				}
				else { 
					while (p->parent && p == p->parent->right)
						p = p->parent;
					p = p->parent;
				}
			}
			return *this;
		}

		template <class Y>
			MapReverseIterator operator--(Y) {
				MapReverseIterator it(*this);
				operator--();
				return it;
			}

		MapReverseIterator operator-(size_type n)
		{
			MapReverseIterator it(*this);	
			while (n > 0)
			{
				it--;
				n--;
			}
			while (n < 0)
			{
				it++;
				n++;
			}
			return (*this);
		}
		bool operator==(const MapReverseIterator & rhs) const {
			return p==rhs.p;
		}
		bool operator!=(const MapReverseIterator & rhs) const {
			return p!=rhs.p;
		}
		ft::pair<Key, Value> & operator*() {
			return p->data;
		}

};

#endif
