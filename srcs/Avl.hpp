/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Avl.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:16:23 by amunoz-p          #+#    #+#             */
/*   Updated: 2021/09/28 14:02:32 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_HPP
#define AVL_HPP

#include "Node.hpp"
#include "MapIterator.hpp"

template<class Key, class Value, class Compare, class Alloc>

class Avl{
    
    public:
        typedef typename Alloc::template rebind<Node<ft::pair<Key, Value> > >::other Node_allocator;
        
        Node_allocator	_node_alloc;
		Node<ft::pair<Key, Value> > *root;
		Node<ft::pair<Key, Value> > *end;
		Node<ft::pair<Key, Value> > *rend;
		int size;
    

        Avl(){
            _node_alloc = Node_allocator(); // esta linea no se si es necesaria
            root = NULL;
            size = 0;
            rend = _node_alloc.allocate(1);
            _node_alloc.construct(rend);
            root = rend;
            end = _node_alloc.allocate(1);
            _node_alloc.construct(end);
            rend->right = end;
            end->parent = rend;
        }
        
        ~Avl(){
            if (root)
                destroy(root);
        }

        void destroy(Node<ft::pair<Key, Value> > *node){
            if (node->right)
                destroy(node->right);
            if (node->left)
                destroy(node->left);
            _node_alloc.destroy(node);
            _node_alloc.deallocate(node, 1);
        }

        Node<ft::pair<Key, Value> > *add(Key hint, Value obj)
        {
            ft::pair<Key, Value> tmp = ft::make_pair(hint, obj);
            Node<ft::pair<Key, Value> > *node = _node_alloc.allocate(1);
            _node_alloc.construct(node, tmp);
            return node;
        }

        Node<ft::pair<Key, Value> >	*add(Key hint, Value obj, Node<ft::pair<Key, Value> > *nd){
            ft::pair<Key, Value> tmp = ft::make_pair(hint, obj);
            Node<ft::pair<Key, Value> > *node = _node_alloc.allocate(1);
            _node_alloc.construct(node, tmp);
            add(nd, node);
            return node;
        }

        void add(Node<ft::pair<Key, Value> > *parent, Node<ft::pair<Key, Value> > * newNode)
        {
            if (parent == rend || (parent != end && Compare()(parent.first, newNode.first))){
                if 
            }
            
        }
};



#endif
