#include "Easyfind.hpp"
#include <list>
#include <vector>
#include <deque>
#include <iostream>

int main( void ) {
    std::vector<int> v;
    std::deque<int> d;
    std::list<int> l;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(7);

    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_back(7);


    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(7);

    const std::list<int> l2(l);

    std::cout << "{" << ((easyfind<std::vector<int> >(v, 3) == v.end())?2147483648:*easyfind<std::vector<int> >(v, 3)) << "}" << std::endl;
    std::cout << "{" << ((easyfind<std::deque<int> >(d, 7) == d.end())?2147483648:*easyfind<std::deque<int> >(d, 7)) << "}" << std::endl;
    std::cout << "{" << ((easyfind<std::list<int> >(l, 8) == l.end())?2147483648:*easyfind<std::list<int> >(l, 8)) << "}" << std::endl;
    std::cout << "{" << ((easyfind<std::list<int> >(l2, 1) == l2.end())?2147483648:*easyfind<std::list<int> >(l2, 1)) << "}" << std::endl;
    std::cout << "{" << ((easyfind<std::list<int> >(l2, 8) == l2.end())?2147483648:*easyfind<std::list<int> >(l2, 8)) << "}" << std::endl;
}