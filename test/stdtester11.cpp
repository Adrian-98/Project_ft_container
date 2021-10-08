/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdtester11.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:45:55 by adrian            #+#    #+#             */
/*   Updated: 2021/10/08 15:55:23 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <map>
#include <iostream>
#include "../srcs/Map.hpp"

int main()
{
    std::map<char,int> map1;

	std::cout << "===Map===" << std::endl;
	std::cout << "===Constructors===" << std::endl;
	std::cout << "___default constructor___" << std::endl;

	std::cout << "size : " << map1.size() << std::endl;
	std::cout << "empty ? : " << map1.empty() << std::endl;
	std::cout << "normal :" << std::endl;
	std::map<char, int>::iterator it = map1.begin();
	while (it != map1.end())
	{
		std::pair<char, int> pr = *it;
		std::cout << pr.first << " | " << pr.second << std::endl;
		it++;
	}
	std::cout << "reverse :" << std::endl;

	std::map<char, int>::reverse_iterator ite = map1.rbegin();
	while (ite != map1.rend())
	{
		std::pair<char, int> pr = *ite;
		std::cout << pr.first << " | " << pr.second << std::endl;
		ite++;
	}

	std::cout << "___manual fill___" << std::endl;

	map1['a'] = 75;
	map1['z'] = 32;
	map1['e'] = 42;

	std::cout << "size : " << map1.size() << std::endl;
	std::cout << "empty ? : " << map1.empty() << std::endl;
	std::cout << "normal :" << std::endl;
	it = map1.begin();
	while (it != map1.end())
	{
		std::pair<char, int> pr = *it;
		std::cout << pr.first << " | " << pr.second << std::endl;
		it++;
	}
	std::cout << "reverse :" << std::endl;

	ite = map1.rbegin();
	while (ite != map1.rend())
	{
		std::pair<char, int> pr = *ite;
		std::cout << pr.first << " | " << pr.second << std::endl;
		ite++;
	}

	std::cout << "___range constructor___" << std::endl;

	std::map<char,int> map2(map1.begin(), map1.begin());

	std::cout << "size : " << map2.size() << std::endl;
	std::cout << "empty ? : " << map2.empty() << std::endl;
	std::cout << "normal :" << std::endl;
	it = map2.begin();
	while (it != map2.end())
	{
		std::pair<char, int> pr = *it;
		std::cout << pr.first << " | " << pr.second << std::endl;
		it++;
	}
	std::cout << "reverse :" << std::endl;

	ite = map2.rbegin();
	while (ite != map2.rend())
	{
		std::pair<char, int> pr = *ite;
		std::cout << pr.first << " | " << pr.second << std::endl;
		ite++;
	}

	std::cout << "___copy constructor___" << std::endl;

	std::map<char,int> map3(map1);

	std::cout << "size : " << map3.size() << std::endl;
	std::cout << "empty ? : " << map3.empty() << std::endl;
	std::cout << "normal :" << std::endl;
	it = map3.begin();
	while (it != map3.end())
	{
		std::pair<char, int> pr = *it;
		std::cout << pr.first << " | " << pr.second << std::endl;
		it++;
	}
	std::cout << "reverse :" << std::endl;

	ite = map3.rbegin();
	while (ite != map3.rend())
	{
		std::pair<char, int> pr = *ite;
		std::cout << pr.first << " | " << pr.second << std::endl;
		ite++;
	}


	std::cout << "___empty copy constructor___" << std::endl;

	std::map<char,int> map4;
	std::map<char,int> map5(map4);

	std::cout << "size : " << map5.size() << std::endl;
	std::cout << "empty ? : " << map5.empty() << std::endl;
	std::cout << "normal :" << std::endl;
	it = map5.begin();
	while (it != map5.end())
	{
		std::pair<char, int> pr = *it;
		std::cout << pr.first << " | " << pr.second << std::endl;
		it++;
	}
	std::cout << "reverse :" << std::endl;

	ite = map5.rbegin();
	while (ite != map5.rend())
	{
		std::pair<char, int> pr = *ite;
		std::cout << pr.first << " | " << pr.second << std::endl;
		ite++;
	}

}