/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:41:55 by adrian            #+#    #+#             */
/*   Updated: 2021/09/06 13:41:23 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Node.hpp"
#include <vector>
#include <iterator>
#include <string>
#include <cstdlib>
#include <stack>
#include <iostream>

# include "ListIterators.hpp"
#include "List.hpp"
#include "Stack.hpp"


bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

int main(void)
{
	
	std::cout << "Testing Stack!!" << std::endl;
	std::cout << "---------------" << std::endl;
	
	std::stack<std::string> original;
	Stack<std::string, List<std::string> > mine;
	
	std::cout << "Testing PUSH & POP:" << std::endl;
	original.push("blue");
	original.push("red");
	original.push("orange");
	mine.push("blue");
	mine.push("red");
	mine.push("orange");
	
	
	
	std::cout << "|Printing ORIGINAL values|" << std::endl;
	std::cout << "First value: " << original.top() << std::endl;
	original.pop();
	std::cout << "Second value: " << original.top() << std::endl;
	original.pop();
	std::cout << "Third value: " << original.top() << std::endl;
	
	std::cout << "|Printing MINE values|" << std::endl;
	std::cout << "First value: " << mine.top() << std::endl;
	mine.pop();
	std::cout << "Second value: " << mine.top() << std::endl;
	mine.pop();
	std::cout << "Third value: " << mine.top() << std::endl;
	
	
	


}