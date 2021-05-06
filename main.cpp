/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:41:55 by adrian            #+#    #+#             */
/*   Updated: 2021/05/06 20:43:45 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "List.hpp"
#include <vector>
#include <iterator>
#include <string>
#include <iostream>
#include <list>


int main(void)
{
	std::list<int> it;
	List<int> ot;
	
	
	ot.pushFront(7);
	ot.pushBack(8);
	std::cout << ot.front() <<std::endl;
	std::cout << ot.back() <<std::endl;


}