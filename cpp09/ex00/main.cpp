#include "BitcoinExchange.hpp"
#include <exception>
#include <iostream>

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "Usage: ./btc <file>";
        return 1;
    }
    try {
        BitcoinExchange btc;
        btc.loadDatabase("data.csv");
        btc.processInput(av[1]);
    }
    catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

