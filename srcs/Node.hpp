/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:59:21 by adrian            #+#    #+#             */
/*   Updated: 2021/09/23 18:19:10 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

# include <limits>


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
			Node(const T& data) : right(nullptr), left(nullptr), data(data), parent(NULL) {}
			
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
			
			int Height (node *root)
			{
				if (root == NULL)
					return -1;
					
				int left = findHeight (root->left); 
				int right = findHeight (root->right); 

				return 1 + max (left, right); 
			}

			




			
			// Node *getright(void){
			// 	return (this->right);
			// }
			// Node *getleft(void){
			// 	return (this->left);
			// }
			// T &getvalue(void) {
			// 	return (this->value);
			// }
			// T const &getvalue(void) const {
			// 	return (this->value);
			// }
			// void setright(Node *right){
			// 	this->right = right;
			// }
			// void setleft(Node *left){
			// 	this->left = left;
			// }
			// void setValue(T &value){
			// 	this->value = value;
			// }
			// Node *clone_whit_value(void){
			// 	return (new Node(NULL, NULL, this->value));
			// }
			
};

#endif