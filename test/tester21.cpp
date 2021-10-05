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

std::ostream& PrintBool(std::ostream& os, bool rhs)
{
	os << (rhs ? "True " : "FALSE");
	return os;
}

void clear(stack<int> & stk)
{
	while (stk.size())
		stk.pop();
}

int main()
{
				
	std::cout << "+++Stack relational operators+++" << std::endl;
	
	stack<int> stk;
	stack<int> stk2;

	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;
	std::cout << "  1  ";
	PrintBool(std::cout << "| == ", stk == stk2);
	PrintBool(std::cout << " | != ", stk != stk2);
	PrintBool(std::cout << " | < ", stk < stk2);
	PrintBool(std::cout << " | > ", stk > stk2);	
	PrintBool(std::cout << " | <= ", stk <= stk2);
	PrintBool(std::cout << " | >= ", stk >= stk2) << " |" << std::endl;;
	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;

	stk.push(4);

	std::cout << "  2  ";
	PrintBool(std::cout << "| == ", stk == stk2);
	PrintBool(std::cout << " | != ", stk != stk2);
	PrintBool(std::cout << " | < ", stk < stk2);
	PrintBool(std::cout << " | > ", stk > stk2);	
	PrintBool(std::cout << " | <= ", stk <= stk2);
	PrintBool(std::cout << " | >= ", stk >= stk2) << " |" << std::endl;;
	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;

	stk2.push(4);

	std::cout << "  3  ";
	PrintBool(std::cout << "| == ", stk == stk2);
	PrintBool(std::cout << " | != ", stk != stk2);
	PrintBool(std::cout << " | < ", stk < stk2);
	PrintBool(std::cout << " | > ", stk > stk2);	
	PrintBool(std::cout << " | <= ", stk <= stk2);
	PrintBool(std::cout << " | >= ", stk >= stk2) << " |" << std::endl;;
	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;
	
	stk.push(0);
	stk2.push(-42);

	std::cout << "  4  ";
	PrintBool(std::cout << "| == ", stk == stk2);
	PrintBool(std::cout << " | != ", stk != stk2);
	PrintBool(std::cout << " | < ", stk < stk2);
	PrintBool(std::cout << " | > ", stk > stk2);	
	PrintBool(std::cout << " | <= ", stk <= stk2);
	PrintBool(std::cout << " | >= ", stk >= stk2) << " |" << std::endl;;
	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;
	
	clear(stk);
	clear(stk2);
	stk.push(2);
	stk.push(13);
	stk2.push(1);
	stk2.push(13);

	std::cout << "  5  ";
	PrintBool(std::cout << "| == ", stk == stk2);
	PrintBool(std::cout << " | != ", stk != stk2);
	PrintBool(std::cout << " | < ", stk < stk2);
	PrintBool(std::cout << " | > ", stk > stk2);	
	PrintBool(std::cout << " | <= ", stk <= stk2);
	PrintBool(std::cout << " | >= ", stk >= stk2) << " |" << std::endl;;
	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;
	
	clear(stk);
	clear(stk2);
	stk.push(1);
	stk.push(13);
	stk2.push(2);
	stk2.push(13);

	std::cout << "  6  ";
	PrintBool(std::cout << "| == ", stk == stk2);
	PrintBool(std::cout << " | != ", stk != stk2);
	PrintBool(std::cout << " | < ", stk < stk2);
	PrintBool(std::cout << " | > ", stk > stk2);	
	PrintBool(std::cout << " | <= ", stk <= stk2);
	PrintBool(std::cout << " | >= ", stk >= stk2) << " |" << std::endl;;
	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;
	
	clear(stk);
	clear(stk2);
	stk.push(0);
	stk.push(1);
	stk.push(2);
	stk.push(3);
	stk2.push(0);
	stk2.push(1);
	stk2.push(2);
	stk2.push(3);
	stk2.push(4);

	std::cout << "  7  ";
	PrintBool(std::cout << "| == ", stk == stk2);
	PrintBool(std::cout << " | != ", stk != stk2);
	PrintBool(std::cout << " | < ", stk < stk2);
	PrintBool(std::cout << " | > ", stk > stk2);	
	PrintBool(std::cout << " | <= ", stk <= stk2);
	PrintBool(std::cout << " | >= ", stk >= stk2) << " |" << std::endl;;
	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;
	
	clear(stk);
	clear(stk2);
	stk.push(0);
	stk.push(1);
	stk.push(2);
	stk.push(3);
	stk2.push(0);
	stk2.push(1);
	stk2.push(2);
	
	std::cout << "  8  ";
	PrintBool(std::cout << "| == ", stk == stk2);
	PrintBool(std::cout << " | != ", stk != stk2);
	PrintBool(std::cout << " | < ", stk < stk2);
	PrintBool(std::cout << " | > ", stk > stk2);	
	PrintBool(std::cout << " | <= ", stk <= stk2);
	PrintBool(std::cout << " | >= ", stk >= stk2) << " |" << std::endl;;
	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;
	
	clear(stk);
	clear(stk2);
	stk.push(-42);
	stk.push(-42);
	stk2.push(-42);
	stk2.push(-42);
	stk2.push(-42);
	
	std::cout << "  9  ";
	PrintBool(std::cout << "| == ", stk == stk2);
	PrintBool(std::cout << " | != ", stk != stk2);
	PrintBool(std::cout << " | < ", stk < stk2);
	PrintBool(std::cout << " | > ", stk > stk2);	
	PrintBool(std::cout << " | <= ", stk <= stk2);
	PrintBool(std::cout << " | >= ", stk >= stk2) << " |" << std::endl;;
	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;
}
