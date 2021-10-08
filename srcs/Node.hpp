/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:59:21 by adrian            #+#    #+#             */
/*   Updated: 2021/10/06 12:58:19 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

# include <limits>
#include "Vector.hpp"
#include "Pair.hpp"
#include "Algorithm.hpp"
#include "MapIterator.hpp"
#include <memory>
#include <cstddef>
#include <limits.h>
#include <stdexcept>


template <typename T>
class Node
{
	public:
			T		data;
			
			Node<T>	*right;
			Node<T>	*left;
			Node<T> *parent;
			
	public:
			Node() : right(NULL), left(NULL), parent(NULL){}
			Node(T data) : data(data), right(NULL), left(NULL), parent(NULL) {}
			
			Node(Node const &copy) : right(copy.right), left(copy.left), data(copy.data), parent(copy.parent){}
			Node &operator=(Node const &copy)
			{
				this->data = copy.data;
				this->right = copy.right;
				this->left = copy.left;
				this->parent = copy.parent;
				return (*this);
			}
			
			virtual ~Node(){}
			
			int height (Node *node)
			{
				if (node == NULL)
					return 0;
				int right = height(node->right);
				int left = height(node->left);
				if (left > right)
					return left + 1;
				return right + 1;
			}

			void checkBalance(Node<T> *node, Node<T> **root)
			{
				if (height(node->left) - height(node->right) > 1 || height(node->left) - height(node->right) < -1) { 
					balance(node, root);
				}
				if (node->parent == NULL) {
					return;
				}
				checkBalance(node->parent, root);
			}

			void balance(Node<T> *node, Node<T> **root)
			{
				bool is_right;
				Node<T> * tmparent = node->parent;
				if (node->parent != NULL) {
					is_right = node->parent->right == node;
				}
				if (height(node->right) - height(node->left) > 1) {
					if (height(node->right->left) < height(node->right->right)) {
						node = left_rotation(node);
					}
					else {
						node = right_left_rotation(node);
					}
				}
				else{
					if (height(node->left->left) > height(node->left->right)) {
						node = right_rotation(node);
					}
					else {
						node = left_right_rotation(node);
					}
				}
				if (tmparent == NULL) {
					*root = node;
				}
				else {
					if (is_right == true)
						tmparent->right  = node;
					else
						tmparent->left = node;
					}
				node->parent = tmparent;				
			}

			Node<T> *left_rotation(Node<T> *node){
				Node<T> *tmp = node->right;
				node->right = tmp->left;
				tmp->left = node;
				tmp->parent = node->parent;
				node->parent = tmp;
				if (node->right)
					node->right->parent = node;
				return tmp; 
			}
			
			Node<T> *right_rotation(Node<T> *node){
				Node<T> *tmp = node->left;
				node->left = tmp->right;
				tmp->right = node;
				tmp->parent = node->parent;
				node->parent = tmp;
				if (node->left)
					node->left->parent = node;
				return tmp; 
			}
			
			Node<T> *right_left_rotation(Node<T> * node) {
				node->right = right_rotation(node->right);
				return left_rotation(node);
			}

			Node<T> *left_right_rotation(Node<T> * node) {
				node->left = left_rotation(node->left);
				return right_rotation(node);
			}			
};

#endif