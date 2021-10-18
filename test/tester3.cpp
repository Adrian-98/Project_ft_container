#include <list>
#include <vector>
#include <iostream>
#include "../srcs/Vector.hpp"
#include "../srcs/Stack.hpp"


int main()
{
	std::cout << "| STACK TEST |\n\n";

    std::list<int> mylist;         // LIST

    ft::Stack<int> first;                 // empty Stack
    ft::Stack<int,std::list<int> > second; // empty Stack with LIST as underlying container
    ft::Stack<int,std::list<int> > third (mylist);

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
    system("leaks a.out");
	return 0;
}