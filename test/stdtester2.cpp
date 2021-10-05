#include <list>
#include <vector>
#include <iostream>
#include <stack>

int main()
{
	std::cout << "| VECTOR TEST |\n\n";
    std::vector<int> first;
    std::vector<int> second(4, 100);
    std::vector<int> third(second.begin(), --second.end());
    std::vector<int> fourth(third);
    std::vector<int> fifth(5, 0);

    fifth = third;

    std::cout << "std::vector<int> second(4, 100):\n";
    for (std::vector<int>::iterator it = second.begin(); it != second.end(); it++)
        std::cout << *it << " ";
    
    std::cout << "\n\nstd::vector<int> third(second.begin(), --second.end()):\n";
    for (std::vector<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";

    std::cout << "\n\nstd::vector<int> fourth(third):\n";
    for (std::vector<int>::iterator it = fourth.begin(); it != fourth.end(); it++)
        std::cout << *it << " ";
    
    std::cout << "\n\nstd::vector<int> fifth(5, 0); \nfifth = third;\n";
    for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
        std::cout << *it << " ";

    std::cout << "\n\nstd::vector<int> first; \n";
    std::cout << "first.insert(first.begin(), 1, 1);\n";
    std::cout << "first.insert(first.end(), 1, 2);\n";
    std::cout << "first.insert(first.end(), 1, 3);\n";

    first.insert(first.begin(), 1, 1);
    first.insert(first.end(), 1, 2);
    first.insert(first.end(), 1, 3);
    
    for (std::vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";

    std::cout << "\nfirst.insert(first.begin(), 2, 2);\n";
    first.insert(first.begin(), 2, 2);

    for (std::vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";

    std::cout << "\nstd::vector<int> anothervector(2, 400);\n";
    std::cout << "first.insert(first.begin(), anothervector.begin(), anothervector.end());\n";    
    std::vector<int> anothervector(2, 400);
    first.insert(first.begin(), anothervector.begin(), anothervector.end());
    for (std::vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";

    std::vector<int> vec(2, 2);
    vec.insert(vec.begin(), 2, 3);
    std::cout << "\nstd::vector<int> vec(2, 2);";
    std::cout << "\nvec.insert(vec.begin(), 2, 3);\n";
    std::cout << "normal vector : ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";
    
    std::vector<int>::reverse_iterator it = vec.rbegin(); 
    std::vector<int>::reverse_iterator ite = vec.rend();
    std::cout << "reverse: ";
    while (it != ite)
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << "\n";

    std::cout << "\nfirst.size(): ";
    std::cout << first.size() << "\n";
    std::cout << "first.max_size(): ";
    std::cout << first.max_size() << "\n";

    std::cout << "\nfirst.resize(9, 6): \n";
    first.resize(9, 6);

    for (std::vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";

    std::cout << "\nfirst.capacity(): ";
    std::cout << first.capacity() << "\n";
    
    std::cout << "\nfirst is empty?\n";
    if (first.empty() == false)
        std::cout << "not empty\n";
    else
        std::cout << "empty\n";

    std::cout << "\nfirst.reserve(10); "<< "\n";     
    first.reserve(10);

    std::cout << "first.capacity(): ";
    std::cout << first.capacity() << "\n";
    std::cout << "\nfirst[1]: ";
    std::cout << first[1] << "\n";
    std::cout << "\nfirst.at(2): ";
    std::cout << first.at(2) << "\n";
    std::cout << "\nfirst.front(): ";
    std::cout << first.front() << "\n";
    std::cout << "\nfirst.back(): ";
    std::cout << first.back() << "\n";

    std::cout << "\nfirst.assign(10, 5):\n";
    first.assign(10, 5);
    for (std::vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n\nfirst.push_back(3):\n";
    first.push_back(3);
    for (std::vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n\nfirst.pop_back(3):\n";
    
    first.pop_back();
    for (std::vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n\nfirst.insert(first.begin(), 2, 2):\n";
    first.insert(first.begin(), 2, 2);

    for (std::vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n\nfirst.erase(first.begin()): \n";
    first.erase(first.begin());
    for (std::vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";

    std::cout << "\nfirst.swap(second): \n";
    first.swap(second);
    for (std::vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";

}
