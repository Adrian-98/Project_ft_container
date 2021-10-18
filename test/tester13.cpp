#include <vector>
#include <map>
#include <iostream>
#include "../srcs/Map.hpp"


int main()
{
	ft::Map<char,int> map1;
	ft::Map<char, int>::iterator it = map1.begin();
	// ft::Map<char, int>::reverse_iterator ite = map1.rbegin();
	ft::Map<char,int> map4;
	ft::Map<char,int> map5(map4);	std::cout << "===Swap===" << std::endl;

	map5['a'] = 1;
	map5['b'] = 2;
	map5['c'] = 3;
	map5['d'] = 4;

	std::cout << "A:";
	it = map5.begin();
	while (it != map5.end())
	{
		ft::pair<char, int> pr = *it;
		std::cout << pr.first << " | " << pr.second << " : ";
		it++;
	}
	std::cout << std::endl<< "B:";
	it = map4.begin();
	while (it != map4.end())
	{
		ft::pair<char, int> pr = *it;
		std::cout << pr.first << " | " << pr.second << " : ";
		it++;
	}
	std::cout << std::endl;
	
	std::cout << "+++SWAP !+++" << std::endl;
	map4.swap(map5);

	std::cout << "A:";
	it = map5.begin();
	while (it != map5.end())
	{
		ft::pair<char, int> pr = *it;
		std::cout << pr.first << " | " << pr.second << " : ";
		it++;
	}
	std::cout << std::endl<< "B:";
	it = map4.begin();
	while (it != map4.end())
	{
		ft::pair<char, int> pr = *it;
		std::cout << pr.first << " | " << pr.second << " : ";
		it++;
	}
	std::cout << std::endl;
	std::cout << "sizeA : " << map5.size() << " | sizeB : " << map4.size() << std::endl;

	std::cout << "______________" << std::endl;
	map5['z'] = 5;
	map5['b'] = 6;
	map5['h'] = 7;
	map5['i'] = 8;

	std::cout << "A:";
	it = map5.begin();
	while (it != map5.end())
	{
		ft::pair<char, int> pr = *it;
		std::cout << pr.first << " | " << pr.second << " : ";
		it++;
	}
	std::cout << std::endl<< "B:";
	it = map4.begin();
	while (it != map4.end())
	{
		ft::pair<char, int> pr = *it;
		std::cout << pr.first << " | " << pr.second << " : ";
		it++;
	}
	std::cout << std::endl;
	std::cout << "sizeA : " << map5.size() << " | sizeB : " << map4.size() << std::endl;
	
	std::cout << "+++SWAP !+++" << std::endl;
	swap(map4,map5);

	std::cout << "A:";
	it = map5.begin();
	while (it != map5.end())
	{
		ft::pair<char, int> pr = *it;
		std::cout << pr.first << " | " << pr.second << " : ";
		it++;
	}
	std::cout << std::endl<< "B:";
	it = map4.begin();
	while (it != map4.end())
	{
		ft::pair<char, int> pr = *it;
		std::cout << pr.first << " | " << pr.second << " : ";
		it++;
	}
	std::cout << std::endl;

	std::cout << "===Clear===" << std::endl;

	map5.clear();

	std::cout << "size : " << map5.size() << std::endl;

	it = map5.begin();
	while (it != map5.end())
	{
		ft::pair<char, int> pr = *it;
		std::cout << pr.first << " | " << pr.second << std::endl;
		it++;
	}
	
	std::cout << "___reclear the same map___" << std::endl;

	map5.clear();

	std::cout << "size : " << map5.size() << std::endl;

	it = map5.begin();
	while (it != map5.end())
	{
		ft::pair<char, int> pr = *it;
		std::cout << pr.first << " | " << pr.second << std::endl;
		it++;
	}
	
	std::cout << "===Find===" << std::endl;
	map5['a'] = 10;
	map5['b'] = 20;
	map5['c'] = 30;

	it = map5.find('a');
	if (it == map5.end())
		std::cout << "Not found" << std::endl;
	else
		std::cout << (*it).first << " : " << (*it).second << std::endl;

	it = map5.find('d');
	if (it == map5.end())
		std::cout << "Not found" << std::endl;
	else
		std::cout << (*it).first << " : " << (*it).second << std::endl;

	it = map5.find('z');
	if (it == map5.end())
		std::cout << "Not found" << std::endl;
	else
		std::cout << (*it).first << " : " << (*it).second << std::endl;

	it = map5.find('c');
	if (it == map5.end())
		std::cout << "Not found" << std::endl;
	else
		std::cout << (*it).first << " : " << (*it).second << std::endl;
	//(system("leaks a.out");
}
