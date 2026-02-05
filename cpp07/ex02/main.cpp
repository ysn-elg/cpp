#include <iostream>
#include <string>
#include "Array.hpp"

int main()
{
    std::cout << "---- int array ----" << std::endl;
    Array<int> a(5);
    for (unsigned int i = 0; i < a.size(); ++i)
        a[i] = (i + 1) * 11;

    for (unsigned int i = 0; i < a.size(); ++i)
        std::cout << "a[" << i << "] = " << a[i] << std::endl;

    std::cout << "---- copy test ----" << std::endl;
    Array<int> b = a;
    b[0] = 637;
    std::cout << "a[0] = " << a[0] << std::endl;
    std::cout << "b[0] = " << b[0] << std::endl;

    std::cout << "---- const test ----" << std::endl;
    const Array<int> c(a);
    std::cout << "c[1] = " << c[1] << std::endl;

    std::cout << "---- out of range ----" << std::endl;
    try {
        std::cout << a[100] << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Exception caught" << std::endl;
    }

    std::cout << "---- string array ----" << std::endl;
    Array<std::string> s(4);
    s[0] = "Paths";
    s[1] = "are";
    s[2] = "found,";
    s[3] = "not made!";
    for (unsigned int i = 0; i < s.size(); ++i)
        std::cout << s[i] << std::endl;

    return 0;
}

/*
#include <cstdlib>
#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}
*/
