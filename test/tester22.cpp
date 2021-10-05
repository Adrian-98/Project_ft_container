#include <list>
#include <iostream>
#include <stack>
#include <vector>
#include "../Stack/Stack.hpp"
#include "../LisT/List.hpp"

#ifdef STD
using namespace std;
#elif FT
using namespace ft;
#endif

int main()
{
	list<int> lst(10);
	int i = 0;
	for (list<int>::iterator it = lst.begin(); it != lst.end(); it++)
	{
		*it = i;
		i++;
	}
	
	std::cout << "===default constructor with default underlying container===" << std::endl;
	stack<int> stk;
	std::cout << "size = " << stk.size() << " _ empty = " << stk.empty() << std::endl;
	
	stk.push(42);;
	std::cout << "size = " << stk.size() << " _ empty = " << stk.empty() << " _ top = " << stk.top() << std::endl;

	stk.push(21);
	std::cout << "size = " << stk.size() << " _ empty = " << stk.empty() << " _ top = " << stk.top() << std::endl;

	stk.pop();
	std::cout << "size = " << stk.size() << " _ empty = " << stk.empty() << " _ top = " << stk.top() << std::endl;


	std::cout << "===copy constructor with list as underlying container===" << std::endl;
	stack<int, list<int> > stk3(lst);

	std::cout << "size = " << stk3.size() << " _ empty = " << stk3.empty() << " _ top = " << stk3.top() << std::endl;
	
	stk3.push(42);;
	std::cout << "size = " << stk3.size() << " _ empty = " << stk3.empty() << " _ top = " << stk3.top() << std::endl;

	stk3.push(21);
	std::cout << "size = " << stk3.size() << " _ empty = " << stk3.empty() << " _ top = " << stk3.top() << std::endl;

	stk3.pop();
	std::cout << "size = " << stk3.size() << " _ empty = " << stk3.empty() << " _ top = " << stk3.top() << std::endl;

	stk3.pop();
	std::cout << "size = " << stk3.size() << " _ empty = " << stk3.empty() << " _ top = " << stk3.top() << std::endl;

	stk3.pop();
	std::cout << "size = " << stk3.size() << " _ empty = " << stk3.empty() << " _ top = " << stk3.top() << std::endl;

}
