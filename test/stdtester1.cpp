#include <list>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;


int main()
{
	std::cout << "| STACK TEST |\n\n";

    vector<int> myvector (2,200);         // vector with 2 elements

    stack<int> first;                 // empty Stack
    stack<int,vector<int> > second; // empty Stack with vector as underlying container
    stack<int,vector<int> > third (myvector);

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
	return 0;	
}