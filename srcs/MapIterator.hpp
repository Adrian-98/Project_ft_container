/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 16:03:50 by amunoz-p          #+#    #+#             */
/*   Updated: 2021/09/27 16:19:37 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITERATOR_HPP
#define MAPITERATOR_HPP

#include "Node.hpp"
#include <iterator>
#include <utility>

template <typename Key, typename Value>

class MapIterator : public std::iterator<std::input_iterator_tag, Key, Value>
{
    private:
            Node<std::pair<Key, Value> > *p;
    public:
    
            MapIterator(Node<std::pair<Key, Value> > *it): p(it){}
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
};



#endif