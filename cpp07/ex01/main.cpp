#include "iter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

template <typename T>
void printElement(T const &element)
{
    std::cout << element << std::endl;
}

void chaos(int &element)
{
    element += -(std::rand() % 570) + 2026;
}

int main()
{
    std::cout << "-------------- String -------------" << std::endl;
    std::string strArr[8] = {
        "Eewh..", "Brother", "Eewh..", "what's",
        "that?", "What's", "that", "brother"
    };
    iter(strArr, 8, printElement);

    std::cout << "-------------- Int -------------" << std::endl;
    int intArr[10] = {0};
    std::srand(std::time(0));
    iter(intArr, 10, chaos);
    iter(intArr, 10, printElement);

    std::cout << "-------------- Double -------------" << std::endl;
    double doubleArr[4] = {3.14159, 9.80665, 299792458.0, 2.71828};
    iter(doubleArr, 4, printElement);

    std::cout << "-------------- Const Int -------------" << std::endl;
    const int constArr[3] = {1, 2, 3};
    iter(constArr, 3, printElement);

    return 0;
}
