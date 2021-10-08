/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Avl.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:16:23 by amunoz-p          #+#    #+#             */
/*   Updated: 2021/10/07 18:43:21 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_HPP
#define AVL_HPP

#include "Node.hpp"
#include "Algorithm.hpp"
#include "MapIterator.hpp"
#include <memory>
#include <cstddef>
#include <limits.h>
#include <stdexcept>



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
            _node_alloc = Node_allocator();
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
            add(root, node);
            return node;
        }

        Node<ft::pair<Key, Value> >	*add(Key hint, Value obj, Node<ft::pair<Key, Value> > *nd)
        {
            ft::pair<Key, Value> tmp = ft::make_pair(hint, obj);
            Node<ft::pair<Key, Value> > * node = _node_alloc.allocate(1);
            _node_alloc.construct(node, tmp);
            add(nd, node);
            return node;
        }

        void add(Node<ft::pair<Key, Value> > *parent, Node<ft::pair<Key, Value> > * newNode)
        {
            if (parent == rend || (parent != end && Compare()(parent->data.first, newNode->data.first)))
            {
                if (parent->right == NULL)
                {
                    parent->right = newNode;
                    newNode->parent = parent;
                    size++;
                } else 
                    add(parent->right, newNode);
                } else
                {
                    if (parent->left == NULL)
                    {
                        parent->left = newNode;
                        newNode->parent = parent;
                        size++;
                    } else 
                        add(parent->left, newNode);
                }
                root->checkBalance(parent, &root);
        }
        

        Node<ft::pair<Key, Value> > *find(Key hint){
            return find_r(root, hint);
        }
        
        Node<ft::pair<Key, Value> > *find_r(Node<ft::pair<Key, Value> > *root, Key hint)
        {
            if (root == NULL)
                return NULL;
            if (root != end &&  root != end && root->data.first == hint)
                return root;
            if (root == end || Compare()(hint, root->data.first)) {
                if (root->left)
                    return find_r(root->left, hint);
                return NULL;
            }
            else{
                if (root->right)
                   return find_r(root->right, hint);
                return NULL;
            }
        }

       
        void remove(Node<ft::pair<Key, Value> > * node) {
            Node<ft::pair<Key, Value> > * parent = node->parent;
            if (node->right == NULL && node->left == NULL) {
                if (parent->right == node)
                    parent->right = NULL;
                else
                    parent->left = NULL;
                _node_alloc.destroy(node);
                _node_alloc.deallocate(node,1);
                parent->checkBalance(parent, &root);
                size--;
                return;
            }
            else if (node->right == NULL) {
                if (parent->right == node) {
                    parent->right = node->left;
                    node->left->parent = parent;
                }
                else
                {
                    parent->left = node->left;
                    node->left->parent = parent;
                }
                _node_alloc.destroy(node);
                _node_alloc.deallocate(node,1);
                parent->checkBalance(parent, &root);
                size--;
                return;
            }
            else if (node->left == NULL) {
                if (parent->right == node) {
                    parent->right = node->right;
                    node->right->parent = parent;
                }
                else
                {
                    parent->left = node->right;
                    node->right->parent = parent;
                }
                _node_alloc.destroy(node);
                _node_alloc.deallocate(node,1);
                parent->checkBalance(parent, &root);
                size--;
                return;
            }
    
            Node<ft::pair<Key, Value> > *iop = in_order_predecessor(node);
            int i = 0;
            if (iop == end)
                i = 1;
            else if (iop == rend)
                i = 2;
            node->data = iop->data;
            remove(iop);
            if (i == 1)
                end = node;
            if (i == 2)
                rend = node;            
        }

        Node<ft::pair<Key, Value> > *in_order_predecessor(Node<ft::pair<Key, Value> > *node){
            if (node->left == NULL)
                return NULL;
            node = node->left;
            while (node->right)
                node = node->right;
            return node;
        }
        
        void print_set(int floor, int index, int height, Node<ft::pair<Key, Value> > * node) {
            for(int x = 0; x < pow(2, height - floor - 1) - 1; x++)
                std::cout << " ";
            int v = 2;
            for (int x = pow(2, floor - 1) ; x > 0; x/=2) {
                if (node != NULL && index / x == 0) {
                        node = node->left;
                }
                else if (node != NULL){
                    index -= x;
                    node = node->right;
                }
            }
            if (node != NULL)
                std::cout << node->data.first;
            else
                std::cout << "_";
            for(int x = 0; x < pow(2, height - floor - 1) - 1; x++)
                std::cout << " ";
        }

        void print_r(Node<ft::pair<Key, Value> > *node, int floor, int height) {
            for (int x = 0; x < pow(2, floor); x++) {
                print_set(floor, x, height, node);
                if (x != pow(2, floor) - 1)
                std::cout << ".";
            }
            if (floor == height - 1)
                return;
            std::cout << std::endl;

            print_r(node, floor + 1, height);
        }

        void print() {
            std::cout << std::endl;
            print_r(root, 0, root->height(root));
            std::cout << std::endl;
        }

        bool is_null(Node<ft::pair<Key, Value> > *node) {
            return (node == NULL || node == end || node == rend);
        }

        Node<ft::pair<Key, Value> > * get_begin() {
            if (size == 0)
                return end;
            if (rend->right)
                return rend->right;
            return rend->parent;
        }

        Node<ft::pair<Key, Value> > * get_rbegin() {
            if (size == 0)
                return rend;
            if (end->left)
                return end->left;
            return end->parent;
        }

        Node<ft::pair<Key, Value> > * get_end() {
            return end;
        }

        Node<ft::pair<Key, Value> > * get_rend() {
            return rend;
        }       
};



#endif
