#include <vector>
#include <map>
#include <iostream>
#include "../srcs/Map.hpp"


int main ()
{
  ft::Map<char,int> mymap;

  mymap['x']=1001;
  mymap['y']=2002;
  mymap['z']=3003;

  std::cout << "mymap contains:\n";

  ft::pair<char,int> highest = *mymap.rbegin();          // last element

  ft::Map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';

//ANSWER MUST BE X=>1001, Y => 2002, Z => 3003 AS IN THE C++ EXAMPLE

  return 0;
}