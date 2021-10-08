#include <vector>
#include <map>
#include <iostream>
#include "../srcs/Map.hpp"

int main()
{
	ft::Map<int,int> map1;
	ft::Map<int, int>::iterator it = map1.begin();
	ft::Map<int, int>::reverse_iterator ite = map1.rbegin();
	ft::Map<int,int> map4;
	ft::Map<int,int> map5(map4);

	std::cout << "===MAX SIZE = " << map5.max_size() << " ===" << std::endl;

	std::cout << "===Acces Read===" << std::endl;

	std::cout << "map1['a'] = "<< map1['a'] << std::endl;
	std::cout << "map1['b'] = "<< map1['b'] << std::endl;
	std::cout << "map1['c'] = "<< map1['c'] << std::endl;

	std::cout << "===Acces Read/Write===" << std::endl;

	std::cout << "size = " << map1.size() << std::endl;

	map1['c'] = 46;
	map1['g'] = 451;
	map1['A'] = 421;

	std::cout << "size = " << map1.size() << std::endl;

	std::cout << "map1['a'] = "<< map1['a'] << std::endl;
	std::cout << "map1['b'] = "<< map1['b'] << std::endl;
	std::cout << "map1['c'] = "<< map1['c'] << std::endl;
	std::cout << "map1['g'] = "<< map1['g'] << std::endl;
	std::cout << "map1['A'] = "<< map1['A'] << std::endl;

	std::cout << "===Inserts===" << std::endl;

	std::cout << "size : " << map5.size() << std::endl;

	ft::pair<const int, int> a('e', 42);
	map5.insert(a);

	ft::pair<const int, int> b('c', 41);
	map5.insert(b);

	ft::pair<const int, int> c('e', 40);
	map5.insert(c);

	ft::pair<const int, int> d('f', 451);
	ft::Map<int, int>::iterator  hint = map5.insert(c).first;
	map5.insert(hint, d);

	std::cout << "size : " << map5.size() << std::endl;

	std::cout << "normal :" << std::endl;
	it = map5.begin();
	while (it != map5.end())
	{
		ft::pair<int, int> pr = *it;
		std::cout << pr.first << " | " << pr.second << std::endl;
		it++;
	}
	std::cout << "reverse :" << std::endl;

	ite = map5.rbegin();
	while (ite != map5.rend())
	{
		ft::pair<int, int> pr = *ite;
		std::cout << pr.first << " | " << pr.second << std::endl;
		ite++;
	}

	std::cout << "===Erase===" << std::endl;

	std::cout << "size : " << map5.size() << std::endl;

	it = map5.begin();
	while (it != map5.end())
	{
		ft::pair<int, int> pr = *it;
		std::cout << pr.first << " | " << pr.second << std::endl;
		it++;
	}

	std::cout << "___erase with it___(c)" << std::endl;
	it = map5.find('c');
	map5.erase(it);

	std::cout << "size : " << map5.size() << std::endl;

	it = map5.begin();
	while (it != map5.end())
	{
		ft::pair<int, int> pr = *it;
		std::cout << pr.first << " | " << pr.second << std::endl;
		it++;
	}

	std::cout << "___erase with key___(f)" << std::endl;
	map5.erase('f');

	std::cout << "size : " << map5.size() << std::endl;

	it = map5.begin();
	while (it != map5.end())
	{
		ft::pair<int, int> pr = *it;
		std::cout << pr.first << " | " << pr.second << std::endl;
		it++;
	}

	std::cout << "___erase everything with range___" << std::endl;
	map5.erase(map5.begin(), map5.end());

	std::cout << "size : " << map5.size() << std::endl;

	it = map5.begin();
	while (it != map5.end())
	{
		ft::pair<int, int> pr = *it;
		std::cout << pr.first << " | " << pr.second << std::endl;
		it++;
	}
}
