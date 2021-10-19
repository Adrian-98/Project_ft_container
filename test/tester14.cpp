
#include "../srcs/Map.hpp"


int main()
{
	ft::Map<char, int>	mmap;


	ft::Map<char, int>::iterator it = mmap.lower_bound('a');

	std::cout << "low(a) = ";
	if (it == mmap.end())
		std::cout << "end" << std::endl;
	else
		std::cout << (*it).first << std::endl;

	std::cout << "up(a) = ";
	it = mmap.upper_bound('a');
	if (it == mmap.end())
		std::cout << "end" << std::endl;
	else
		std::cout << (*it).first << std::endl;

	mmap['b'] = 10;
	std::cout << "->add b" << std::endl;

	std::cout << "low(a) = ";
	it = mmap.lower_bound('a');
	if (it == mmap.end())
		std::cout << "end" << std::endl;
	else
		std::cout << (*it).first << std::endl;

	std::cout << "up(a) = ";
	it = mmap.upper_bound('a');
	if (it == mmap.end())
		std::cout << "end" << std::endl;
	else
		std::cout << (*it).first << std::endl;

	std::cout << "low(b) = ";
	it = mmap.lower_bound('b');
	if (it == mmap.end())
		std::cout << "end" << std::endl;
	else
		std::cout << (*it).first << std::endl;

	std::cout << "up(b) = ";
	it = mmap.upper_bound('b');
	if (it == mmap.end())
		std::cout << "end" << std::endl;
	else
		std::cout << (*it).first << std::endl;

	std::cout << "low(c) = ";
	it = mmap.lower_bound('c');
	if (it == mmap.end())
		std::cout << "end" << std::endl;
	else
		std::cout << (*it).first << std::endl;

	std::cout << "up(c) = ";
	it = mmap.upper_bound('c');
	if (it == mmap.end())
		std::cout << "end" << std::endl;
	else
		std::cout << (*it).first << std::endl;


	mmap['e'] = 10;
	std::cout << "->add e" << std::endl;

	std::cout << "low(a) = ";
	it = mmap.lower_bound('a');
	if (it == mmap.end())
		std::cout << "end" << std::endl;
	else
		std::cout << (*it).first << std::endl;

	std::cout << "up(a) = ";
	it = mmap.upper_bound('a');
	if (it == mmap.end())
		std::cout << "end" << std::endl;
	else
		std::cout << (*it).first << std::endl;

	std::cout << "low(b) = ";
	it = mmap.lower_bound('b');
	if (it == mmap.end())
		std::cout << "end" << std::endl;
	else
		std::cout << (*it).first << std::endl;

	std::cout << "up(b) = ";
	it = mmap.upper_bound('b');
	if (it == mmap.end())
		std::cout << "end" << std::endl;
	else
		std::cout << (*it).first << std::endl;

	std::cout << "low(c) = ";
	it = mmap.lower_bound('c');
	if (it == mmap.end())
		std::cout << "end" << std::endl;
	else
		std::cout << (*it).first << std::endl;

	std::cout << "up(c) = ";
	it = mmap.upper_bound('c');
	if (it == mmap.end())
		std::cout << "end" << std::endl;
	else
		std::cout << (*it).first << std::endl;

	std::cout << "low(d) = ";	
	it = mmap.lower_bound('d');
	if (it == mmap.end())
		std::cout << "end" << std::endl;
	else
		std::cout << (*it).first << std::endl;
	
	std::cout << "up(d) = ";
	it = mmap.upper_bound('d');
	if (it == mmap.end())
		std::cout << "end" << std::endl;
	else
		std::cout << (*it).first << std::endl;

	mmap['c'] = 10;
	std::cout << "->add c" << std::endl;

	std::cout << "low(a) = ";
	it = mmap.lower_bound('a');
	if (it == mmap.end())
		std::cout << "end" << std::endl;
	else
		std::cout << (*it).first << std::endl;

	std::cout << "up(a) = ";
	it = mmap.upper_bound('a');
	if (it == mmap.end())
		std::cout << "end" << std::endl;
	else
		std::cout << (*it).first << std::endl;

	std::cout << "low(b) = ";
	it = mmap.lower_bound('b');
	if (it == mmap.end())
		std::cout << "end" << std::endl;
	else
		std::cout << (*it).first << std::endl;

	std::cout << "up(b) = ";
	it = mmap.upper_bound('b');
	if (it == mmap.end())
		std::cout << "end" << std::endl;
	else
		std::cout << (*it).first << std::endl;

	std::cout << "low(c) = ";
	it = mmap.lower_bound('c');
	if (it == mmap.end())
		std::cout << "end" << std::endl;
	else
		std::cout << (*it).first << std::endl;

	std::cout << "up(c) = ";
	it = mmap.upper_bound('c');
	if (it == mmap.end())
		std::cout << "end" << std::endl;
	else
		std::cout << (*it).first << std::endl;

	std::cout << "low(d) = ";	
	it = mmap.lower_bound('d');
	if (it == mmap.end())
		std::cout << "end" << std::endl;
	else
		std::cout << (*it).first << std::endl;
	
	std::cout << "up(d) = ";
	it = mmap.upper_bound('d');
	if (it == mmap.end())
		std::cout << "end" << std::endl;
	else
		std::cout << (*it).first << std::endl;

	std::cout << "low(e) = ";	
	it = mmap.lower_bound('e');
	if (it == mmap.end())
		std::cout << "end" << std::endl;
	else
		std::cout << (*it).first << std::endl;
	
	std::cout << "up(e) = ";
	it = mmap.upper_bound('e');
	if (it == mmap.end())
		std::cout << "end" << std::endl;
	else
		std::cout << (*it).first << std::endl;

	std::cout << "low(f) = ";	
	it = mmap.lower_bound('f');
	if (it == mmap.end())
		std::cout << "end" << std::endl;
	else
		std::cout << (*it).first << std::endl;
	
	std::cout << "up(f) = ";
	it = mmap.upper_bound('f');
	if (it == mmap.end())
		std::cout << "end" << std::endl;
	else
		std::cout << (*it).first << std::endl;


	ft::pair<ft::Map<char,int>::iterator,ft::Map<char,int>::iterator> ret = mmap.equal_range('b');
	ft::Map<char, int>::iterator	itlow = mmap.lower_bound ('b');  // itlow points to b
	ft::Map<char, int>::iterator	itup = mmap.upper_bound ('d');   // itup points to e (not d!)

	mmap['a']=20;
	itup = mmap.upper_bound ('d');
	itlow = mmap.lower_bound ('b');  

	mmap.erase(itlow,itup);
	ret = mmap.equal_range('b');
	mmap['e']=100;

	itup = mmap.upper_bound ('d');
	itlow = mmap.lower_bound ('b');   
		

	mmap.erase(itlow,itup);
	ret = mmap.equal_range('b');

	mmap['b']=40;
	mmap['c']=60;
	mmap['d']=80;
	itlow = mmap.lower_bound ('b');  // itlow points to b
  	itup = mmap.upper_bound ('d');   // itup points to e (not d!)  

	mmap.erase(itlow, itup);        // erases [itlow,itup)

	mmap['a']=10;
  	mmap['b']=20;
  	mmap['c']=30;
	for (ft::Map<char,int>::iterator it = mmap.begin(); it != mmap.end(); ++it)
		std::cout << (*it).first << " => " << (*it).second << '\n';

  ret = mmap.equal_range('b');

  std::cout << "lower bound points to: ";
  std::cout << (*ret.first).first << " => " << (*ret.first).second << '\n';

  std::cout << "upper bound points to: ";
  std::cout << (*ret.second).first << " => " << (*ret.second).second << '\n';
  //system("leaks a.out");
  return 0;
}