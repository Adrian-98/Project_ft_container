/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 12:49:58 by adrian            #+#    #+#             */
/*   Updated: 2021/10/04 13:57:59 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "srcs/Vector.hpp"
#include <set>
#include "srcs/Algorithm.hpp"
#include "srcs/Stack.hpp"
#include "srcs/Map.hpp"


void test_stack()
{
    std::cout << "| STACK TEST |\n\n";

    ft::Vector<int> myvector (2,200);         // vector with 2 elements

    ft::Stack<int> first;                 // empty Stack
    ft::Stack<int,ft::Vector<int> > second; // empty Stack with vector as underlying container
    ft::Stack<int,ft::Vector<int> > third (myvector);

    std::cout << "size of first: " << first.size() << '\n';
    std::cout << "size of second: " << second.size() << '\n';
    std::cout << "size of third: " << third.size() << "\n\n";

    std::cout << "second empty?: ";
    if (second.empty() == false)
        std::cout << "not empty\n";
    else
        std::cout << "empty\n";
  
    std::cout << "third empty?: ";
    if (third.empty() == false)
        std::cout << "not empty\n\n";
    else
        std::cout << "empty\n\n";

    third.push(10);
    third.push(7);
    std::cout << "third.push(10)\n";
    std::cout << "third.push(7)\n\n"; 
    std::cout << "third.top() is now " << third.top() << "\n\n";
    std::cout << "third.size() is now: " << third.size() << std::endl;
    std::cout << "\n";
    third.pop();
    third.pop();
    std::cout << "third.pop()\n";
    std::cout << "third.pop()\n";
    std::cout << "third.front() is now: " << third.top() << '\n';
    std::cout << "third.size() is now: " << third.size() << std::endl;
    std::cout << "\n";
}


void test_vector()
{
    std::cout << "| VECTOR TEST |\n\n";
    ft::Vector<int> first;
    ft::Vector<int> second(4, 100);
    ft::Vector<int> third(second.begin(), --second.end());
    ft::Vector<int> fourth(third);
    ft::Vector<int> fifth(5, 0);

    fifth = third;

    std::cout << "ft::Vector<int> second(4, 100):\n";
    for (ft::Vector<int>::iterator it = second.begin(); it != second.end(); it++)
        std::cout << *it << " ";
    
    std::cout << "\n\nft::Vector<int> third(second.begin(), --second.end()):\n";
    for (ft::Vector<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";

    std::cout << "\n\nft::Vector<int> fourth(third):\n";
    for (ft::Vector<int>::iterator it = fourth.begin(); it != fourth.end(); it++)
        std::cout << *it << " ";
    
    std::cout << "\n\nft::Vector<int> fifth(5, 0); \nfifth = third;\n";
    for (ft::Vector<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
        std::cout << *it << " ";

    std::cout << "\n\nft::Vector<int> first; \n";
    std::cout << "first.insert(first.begin(), 1, 1);\n";
    std::cout << "first.insert(first.end(), 1, 2);\n";
    std::cout << "first.insert(first.end(), 1, 3);\n";

    first.insert(first.begin(), 1, 1);
    first.insert(first.end(), 1, 2);
    first.insert(first.end(), 1, 3);
    
    for (ft::Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";

    std::cout << "\nfirst.insert(first.begin(), 2, 2);\n";
    first.insert(first.begin(), 2, 2);

    for (ft::Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";

    std::cout << "\nft::Vector<int> anothervector(2, 400);\n";
    std::cout << "first.insert(first.begin(), anothervector.begin(), anothervector.end());\n";    
    ft::Vector<int> anothervector(2, 400);
    first.insert(first.begin(), anothervector.begin(), anothervector.end());
    for (ft::Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";

    ft::Vector<int> vec(2, 2);
    vec.insert(vec.begin(), 2, 3);
    std::cout << "\nft::Vector<int> vec(2, 2);";
    std::cout << "\nvec.insert(vec.begin(), 2, 3);\n";
    std::cout << "normal vector : ";
    for (ft::Vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";
    
    ft::Vector<int>::reverse_iterator it = vec.rbegin(); 
    ft::Vector<int>::reverse_iterator ite = vec.rend();
    std::cout << "reverse: ";
    while (it != ite)
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << "\n";

    std::cout << "\nfirst.size(): ";
    std::cout << first.size() << "\n";
    std::cout << "first.max_size(): ";
    std::cout << first.max_size() << "\n";

    std::cout << "\nfirst.resize(9, 6): \n";
    first.resize(9, 6);

    for (ft::Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";

    std::cout << "\nfirst.capacity(): ";
    std::cout << first.capacity() << "\n";
    
    std::cout << "\nfirst is empty?\n";
    if (first.empty() == false)
        std::cout << "not empty\n";
    else
        std::cout << "empty\n";

    std::cout << "\nfirst.reserve(10); "<< "\n";     
    first.reserve(10);

    std::cout << "first.capacity(): ";
    std::cout << first.capacity() << "\n";
    std::cout << "\nfirst[1]: ";
    std::cout << first[1] << "\n";
    std::cout << "\nfirst.at(2): ";
    std::cout << first.at(2) << "\n";
    std::cout << "\nfirst.front(): ";
    std::cout << first.front() << "\n";
    std::cout << "\nfirst.back(): ";
    std::cout << first.back() << "\n";

    std::cout << "\nfirst.assign(10, 5):\n";
    first.assign(10, 5);
    for (ft::Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n\nfirst.push_back(3):\n";
    first.push_back(3);
    for (ft::Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n\nfirst.pop_back(3):\n";
    
    first.pop_back();
    for (ft::Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n\nfirst.insert(first.begin(), 2, 2):\n";
    first.insert(first.begin(), 2, 2);

    for (ft::Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n\nfirst.erase(first.begin()): \n";
    first.erase(first.begin());
    for (ft::Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";

    std::cout << "\nfirst.swap(second): \n";
    first.swap(second);
    for (ft::Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";
}


void ft_Map01(){
    
    Map<char,int> Map1;

	std::cout << "===Map===" << std::endl;
	std::cout << "===Constructors===" << std::endl;
	std::cout << "___default constructor___" << std::endl;

	std::cout << "size : " << Map1.size() << std::endl;
	std::cout << "empty ? : " << Map1.empty() << std::endl;
	std::cout << "normal :" << std::endl;
	Map<char, int>::iterator it = Map1.begin();
	while (it != Map1.end())
	{
		ft::pair<char, int> pr = *it;
		std::cout << pr.first << " | " << pr.second << std::endl;
		it++;
	}
	std::cout << "reverse :" << std::endl;

	Map<char, int>::reverse_iterator ite = Map1.rbegin();
	while (ite != Map1.rend())
	{
		ft::pair<char, int> pr = *ite;
		std::cout << pr.first << " | " << pr.second << std::endl;
		ite++;
	}

	std::cout << "___manual fill___" << std::endl;

	Map1['a'] = 75;
	Map1['z'] = 32;
	Map1['e'] = 42;

	std::cout << "size : " << Map1.size() << std::endl;
	std::cout << "empty ? : " << Map1.empty() << std::endl;
	std::cout << "normal :" << std::endl;
	it = Map1.begin();
	while (it != Map1.end())
	{
		ft::pair<char, int> pr = *it;
		std::cout << pr.first << " | " << pr.second << std::endl;
		it++;
	}
	std::cout << "reverse :" << std::endl;

	ite = Map1.rbegin();
	while (ite != Map1.rend())
	{
		ft::pair<char, int> pr = *ite;
		std::cout << pr.first << " | " << pr.second << std::endl;
		ite++;
	}

	std::cout << "___range constructor___" << std::endl;

	Map<char,int> Map2(Map1.begin(), Map1.begin());

	std::cout << "size : " << Map2.size() << std::endl;
	std::cout << "empty ? : " << Map2.empty() << std::endl;
	std::cout << "normal :" << std::endl;
	it = Map2.begin();
	while (it != Map2.end())
	{
		ft::pair<char, int> pr = *it;
		std::cout << pr.first << " | " << pr.second << std::endl;
		it++;
	}
	std::cout << "reverse :" << std::endl;

	ite = Map2.rbegin();
	while (ite != Map2.rend())
	{
		ft::pair<char, int> pr = *ite;
		std::cout << pr.first << " | " << pr.second << std::endl;
		ite++;
	}

	std::cout << "___copy constructor___" << std::endl;

	Map<char,int> Map3(Map1);

	std::cout << "size : " << Map3.size() << std::endl;
	std::cout << "empty ? : " << Map3.empty() << std::endl;
	std::cout << "normal :" << std::endl;
	it = Map3.begin();
	while (it != Map3.end())
	{
		ft::pair<char, int> pr = *it;
		std::cout << pr.first << " | " << pr.second << std::endl;
		it++;
	}
	std::cout << "reverse :" << std::endl;

	ite = Map3.rbegin();
	while (ite != Map3.rend())
	{
		ft::pair<char, int> pr = *ite;
		std::cout << pr.first << " | " << pr.second << std::endl;
		ite++;
	}


	std::cout << "___empty copy constructor___" << std::endl;

	Map<char,int> Map4;
	Map<char,int> Map5(Map4);

	std::cout << "size : " << Map5.size() << std::endl;
	std::cout << "empty ? : " << Map5.empty() << std::endl;
	std::cout << "normal :" << std::endl;
	it = Map5.begin();
	while (it != Map5.end())
	{
		ft::pair<char, int> pr = *it;
		std::cout << pr.first << " | " << pr.second << std::endl;
		it++;
	}
	std::cout << "reverse :" << std::endl;

	ite = Map5.rbegin();
	while (ite != Map5.rend())
	{
		ft::pair<char, int> pr = *ite;
		std::cout << pr.first << " | " << pr.second << std::endl;
		ite++;
	}
}

int main (void)
{
    test_stack();
    return 0;
}
