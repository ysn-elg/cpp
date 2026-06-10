#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
    std::cout << "=== Subject test ===" << std::endl;

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);

    std::cout << "\n=== Reverse iteration ===" << std::endl;

    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();

    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }

    std::cout << "\n=== Copy constructor ===" << std::endl;

    MutantStack<int> copy(mstack);

    for (MutantStack<int>::iterator i = copy.begin();
         i != copy.end();
         ++i)
        std::cout << *i << std::endl;

    std::cout << "\n=== Assignment operator ===" << std::endl;

    MutantStack<int> assign;
    assign = mstack;

    for (MutantStack<int>::iterator i = assign.begin();
         i != assign.end();
         ++i)
        std::cout << *i << std::endl;

    std::cout << "\n=== Compare with std::list ===" << std::endl;

    std::list<int> lst;

    lst.push_back(5);
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    for (std::list<int>::iterator i = lst.begin();
         i != lst.end();
         ++i)
        std::cout << *i << std::endl;

    return 0;
}
