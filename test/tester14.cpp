#include <vector>
#include <map>
#include <iostream>
#include "../Map/Map.hpp"

#ifdef STD
using namespace std;
#elif FT
using namespace ft;
#endif

int main()
{
	map<char, int>				mmap;

  pair<map<char,int>::iterator,map<char,int>::iterator> ret = mmap.equal_range('b');
	map<char, int>::iterator	itow = mmap.lower_bound ('b');  // itlow points to b
	map<char, int>::iterator	itp = mmap.upper_bound ('d');   // itup points to e (not d!)

	mmap['a']=20;
	itow = mmap.upper_bound ('b');
	itp = mmap.lower_bound ('d');   // itup points to e (not d!)

	mmap.erase(itow,itp);
	ret = mmap.equal_range('b');
	mmap['e']=100;

	itow = mmap.upper_bound ('b');
	itp = mmap.lower_bound ('d');   // itup points to e (not d!)
		// std::cout << (*itow).first << " =g> " << (*itow).second << '\n';
		// std::cout << (*itp).first << " =g> " << (*itp).second << '\n';
	
	mmap.erase(itow,itp);
	ret = mmap.equal_range('b');
	        // erases [itlow,itup)
	mmap['b']=40;
	mmap['c']=60;
	mmap['d']=80;
	itow = mmap.upper_bound ('b');
	itp = mmap.lower_bound ('d');   // itup points to e (not d!)

	mmap.erase(itow,itp);        // erases [itlow,itup)

	for (map<char,int>::iterator it = mmap.begin(); it != mmap.end(); ++it)
		std::cout << (*it).first << " => " << (*it).second << '\n';



ret = mmap.equal_range('b');
  std::cout << "upper bound points to: ";
  std::cout << (*ret.first).first << " => " << (*ret.first).second << '\n';

  std::cout << "lower bound points to: ";
  std::cout << (*ret.second).first << " => " << (*ret.second).second << '\n';



  return 0;
}