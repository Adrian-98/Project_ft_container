/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:59:21 by adrian            #+#    #+#             */
/*   Updated: 2021/10/04 13:30:26 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

# include <limits>
#include "Vector.hpp"
#include "Pair.hpp"


template <typename T>
class Node
{
	public:
			T		data;
			
			Node<T>	*right;
			Node<T>	*left;
			Node<T> *parent;
	public:
			Node() :data(NULL), right(nullptr), left(nullptr), parent(NULL){}
			Node(const T& data) : data(data), right(nullptr), left(nullptr), parent(NULL) {}
			
			Node(Node const &copy) : right(copy.right), left(copy.left), data(copy.data), parent(copy.parent){}
			Node &operator=(Node const &copy)
			{
				this->right = copy.right;
				this->left = copy.left;
				this->data = copy.data;
				this->parent = copy.parent;
				return (*this);
			}
			
			virtual ~Node(){}
			
			int height (Node *root)
			{
				if (root == NULL)
					return -1;
					
				int left = height (root->left); 
				int right = height (root->right); 

				return 1 + ft::max (left, right); 
			}

			void checkbalance(Node<T> *node, Node<T> **root)
			{
				if (height(node->right) - height(node->left) > 1 || height(node->right) - height(node->left)  < -1)
					balance(node, root);
				if (this->parent == NULL)
					return;
				checkbalance(this->parent, root);
			}

			void balance(Node<T> *node, Node<T> **root)
			{
				bool is_right;
				Node<T> *tmparent = node->parent;
				if (node->parent != NULL)
					is_right = node->parent->right == node; //see which branch we are at;
				if (height(node->right) - height(node->left) == 2){
					if (height(node->right->right) - height(node->right->left) == 1)
						node = left_rotation(node);
					else if (height(node->right->right) - height(node->right->left) == -1)
						node = right_left_rotation(node);
				}
				else {
					if (height(node->right->right) - height(node->right->left) == 1)
						node = left_right_rotation(node);
					else if (height(node->right->right) - height(node->right->left) == -1)
						node = right_rotation(node);
				}
				if (tmparent == NULL)
					*root = node;
				else {
					if (is_right == true)
						tmparent->right = node;
					else
						tmparent->left = node;
				}
				node->parent = tmparent;				
			}

			Node<T> *left_rotate(Node<T> *node){
				Node<T> *tmp = node->right;
				node->right = tmp->left;
				tmp->left = node;
				tmp->parent = node->parent;
				node->parent = tmp;
				if (node->right)
					node->right->parent = node;
				return tmp; 
			}
			
			Node<T> *right_rotate(Node<T> *node){
				Node<T> *tmp = node->left;
				node->left = tmp->right;
				tmp->right = node;
				tmp->parent = node->parent;
				node->parent = tmp;
				if (node->left)
					node->left->parent = node;
				return tmp; 
			}
			
			Node<T> *right_left_rotate(Node<T> * node) {
				node->right = right_rotate(node->right);
				return left_rotate(node);
			}

			Node<T> *left_right_rotate(Node<T> * node) {
				node->left = left_rotate(node->left);
				return right_rotate(node);
			}			
};

#endif