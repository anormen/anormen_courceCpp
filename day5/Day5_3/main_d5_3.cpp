//We want to generate 1024 random integers, then given a newrandom number; find two integers which are the closest
// to the given number (smaller, and bigger) with less than twelve lookups.

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort

int main(){

    std::list<int> myList;


    for ( int i = 0; i < 1024; i++)
   {
       int n = std::rand();
       myList.push_back(n);
       //std::cout << n << ", ";
   }


    myList.sort();

    int num = std::rand();
    std::cout << "New randsom nr is " << num <<std::endl;

    std::list<int> ::iterator low;
    std::list<int> ::iterator up;

    low = std::lower_bound(myList.begin(), myList.end(), num);
    up = low--;

    std::cout << "closest smaller is " << *low << '\n';
    std::cout << "closest bigger is " << *up << '\n';





    return 0;
}