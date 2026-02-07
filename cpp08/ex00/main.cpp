#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    try {
        std::vector<int> v;
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);

        std::cout << "Found in vector: " << *easyfind(v, 20) << std::endl;

        std::list<int> l;
        l.push_back(5);
        l.push_back(15);

        std::cout << "Found in list: " << *easyfind(l, 15) << std::endl;

        // This will throw
        std::cout << *easyfind(v, 99) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
