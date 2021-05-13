/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:41:55 by adrian            #+#    #+#             */
/*   Updated: 2021/05/13 19:14:38 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Node.hpp"
#include <vector>
#include <iterator>
#include <string>

#include <iostream>
# include "ListIterators.hpp"
#include "List.hpp"

bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

int main(void)
{
	//std::list<int> ot;
	List<int> ot;
	
	
	ot.pushFront(7);
	ot.pushFront(7);
	ot.pushFront(7);
	ot.pushFront(5);
	ot.pushFront(5);
	ot.pushFront(5);
	ot.pushFront(7);
	ot.pushFront(7);
	ot.pushFront(7);
	ot.pushFront(7);
	ot.pushFront(7);
	ot.unique();
	List<int>::iterator first = ot.begin();
	List<int>::iterator last = ot.end();
	while (first != last)
		std::cout << *first++ << std::endl;


}