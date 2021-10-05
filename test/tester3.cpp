#include <vector>
#include <list>
#include <iostream>
#include "../Vector/Vector.hpp"

#ifdef STD
using namespace std;
#elif FT
using namespace ft;
#endif

int main()
{
	std::cout << "+++vector modifiers+++" << std::endl;
	vector<int> vec;
	
	std::cout << "===insert begin===" << std::endl;
	for (int i = 0; i < 15; i++)
		vec.insert(vec.begin(), i);
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << "_" << *it << std::endl;
	
	vec.clear();
	
	std::cout << "===insert end===" << std::endl;
	for (int i = 0; i < 15; i++)
		vec.insert(vec.end(), i);
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << "_" << *it << std::endl;
	
	vec.clear();

	std::cout << "===insert returns===" << std::endl;
	for (int i = 0; i < 15; i++)
	{
		vector<int>::iterator r = vec.insert(vec.begin(), i);
		std::cout << "_" << *r << std::endl;
	}
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << "_" << *it << std::endl;
	
	//create incremental vector and list
	vector<int> vek(10);
	for (int i = 0; i < 10; i++)
		vek[i] = i;
	
	int i = 0;
	std::list<int> lst(10);
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
	{
		*it = i;
		i++;
	}

	vec.clear();

	std::cout << "===insert with interval==" << std::endl;
	vec.insert(vec.begin(), vek.begin(), vek.end());
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << "_" << *it << std::endl;

	vec.clear();

	std::cout << "===insert with list interval==" << std::endl;
	vec.insert(vec.begin(), lst.begin(), lst.end());
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << "_" << *it << std::endl;

	std::cout << "===insert itself==" << std::endl;
	vector<int>::iterator it = vec.begin();
	it++;
	it++;
	vec.insert(it, vec.begin(), vec.end());
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << "_" << *it << std::endl;
	
	std::cout << "===assign==" << std::endl;
	vec.assign(vek.begin(), vek.end());
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << "_" << *it << std::endl;

	std::cout << "===assign itself==" << std::endl;
	vec.assign(vec.begin(), vec.end());
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << "_" << *it << std::endl;

	std::cout << "===assign with list==" << std::endl;
	vec.assign(lst.begin(), lst.end());
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << "_" << *it << std::endl;

	std::cout << "===assign with values==" << std::endl;
	vec.assign(13,14);
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << "_" << *it << std::endl;

	std::cout << "===push back==" << std::endl;
	vec.push_back(0);
	vec.push_back(1);
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << "_" << *it << std::endl;
	
	std::cout << "===pop back==" << std::endl;
	vec.pop_back();
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << "_" << *it << std::endl;
}
